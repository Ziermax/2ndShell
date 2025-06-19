#include "struct.h"

void	manage_special(char *line, t_token **token, int *i, int type)
{
	if (type == T_APPEND || type == T_HEREDOC)
	{
		ft_add_token(token, line, *i, 2);
		token_add_type(token, type);
		(*i)++;
	}
	else
	{
		ft_add_token(token, line, *i, 1);
		token_add_type(token, type);
	}
	(*i)++;
}

int	manage_quotes(char *line, t_token **token, int *i, int *exit_status)
{
	char	quote_char;
	int		j;

	quote_char = line[*i];
	j = (*i) + 1;
	while (line[j] && line[j] != quote_char)
		j++;
	if (line[j] == quote_char)
	{
		ft_add_token(token, line, *i, j - (*i) + 1);
		token_add_type(token, T_GENERAL);
		(*i) = j + 1;
		return (1);
	}
	else
	{
		printf("minishell: unclosed quotes\n");
		*exit_status = 2;
		ft_free_tokenlist(token);
		return (0);
	}
}

void	manage_general(char *line, t_token **token, int *i)
{
	int	j;

	j = (*i);
	while (line[j] && !ft_isspace(line[j]) && get_type(line, j) == T_GENERAL
		&& line[j] != 34 && line[j] != 39)
		j++;
	if (j > (*i)) {
		ft_add_token(token, line, (*i), j - (*i));
		token_add_type(token, T_GENERAL);
	}
	(*i) = j;
}
