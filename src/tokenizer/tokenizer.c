#include "struct.h"

static int	check_syntaxis(t_token *node, int *exit_status);
static void	token_cmd_assigntype(t_token *node);

void	ft_token(char *line, t_token **token, int *exit_status)
{
	int	i;
	int	type;

	i = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		type = get_type(line, i);
		if (type != T_GENERAL)
			manage_special(line, token, &i, type);
		else if (line[i] == 34 || line[i] == 39)
		{
			if (!manage_quotes(line, token, &i, exit_status))
				break ;
		}
		else
			manage_general(line, token, &i);
	}
	if (!check_syntaxis(*token, exit_status))
	{
		ft_free_tokenlist(token);
		return ;
	}
	token_cmd_assigntype(*token);
}


int	check_pipe_syntaxis(t_token *node, int *exit_status)
{
	if (node->type == T_PIPE)
	{
		printf("%s |\n", ERR_TOKEN);
		*exit_status = 2;
		return (0);
	}
	while (node)
	{
		if ((node->type == T_PIPE && !node->next) || (node->type == T_PIPE
				&& node->next->type == T_PIPE))
		{
			printf("%s |\n", ERR_TOKEN);
			*exit_status = 2;
			return (0);
		}
		node = node->next;
	}
	return (1);
}

static int	check_syntaxis(t_token *node, int *exit_status)
{
	if (!node)
		return (0);
	if (!check_pipe_syntaxis(node, exit_status))
		return (0);
	while (node->next)
	{
		if ((node->type == T_REDIR_OUT || node->type == T_APPEND
				|| node->type == T_REDIR_IN || node->type == T_HEREDOC)
			&& node->next->type != T_GENERAL)
		{
			printf("%s %s\n", ERR_TOKEN, node->next->word);
			*exit_status = 2;
			return (0);
		}
		node = node->next;
	}
	return (1);
}

static void	token_cmd_assigntype(t_token *node)
{
	if (node->type == T_GENERAL)
		node->type = T_CMD;
	while (node->next)
	{
		if (node->type == T_REDIR_IN && node->next->type == T_GENERAL)
			node->next->type = T_INFILE;
		else if (node->type == T_HEREDOC && node->next->type == T_GENERAL)
			node->next->type = T_LIMITER;
		else if (node->type == T_LIMITER && node->next->type == T_GENERAL)
			node->next->type = T_CMD;
		else if (node->type == T_INFILE && node->next->type == T_GENERAL)
			node->next->type = T_CMD;
		else if (node->type == T_CMD && node->next->type == T_GENERAL)
			node->next->type = T_CMD;
		else if (node->type == T_PIPE && node->next->type == T_GENERAL)
			node->next->type = T_CMD;
		else if ((node->type == T_REDIR_OUT || node->type == T_APPEND)
				&& node->next->type == T_GENERAL)
			node->next->type = T_OUTFILE;
		else if (node->type == T_OUTFILE && node->next->type == T_GENERAL)
			node->next->type = T_CMD;
		node = node->next;
	}
}
