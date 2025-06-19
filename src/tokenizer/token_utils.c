#include "struct.h"

int	get_type(char *str, int i)
{
	if (str[i] == '|')
		return (T_PIPE);
	else if (str[i] == '>')
	{
		if (str[i + 1] == '>')
			return (T_APPEND);
		return (T_REDIR_IN);
	}
	else if (str[i] == '<')
	{
		if (str[i + 1] == '<')
			return (T_HEREDOC);
		return (T_REDIR_OUT);
	}
	return (T_GENERAL);
}

void	token_add_type(t_token **token, int type)
{
	t_token	*actual;

	actual = *token;
	while (actual->next != NULL)
		actual = actual->next;
	actual->type = type;
}

void	ft_add_token(t_token **token, char *line, int i, int token_size)
{
	t_token	*new;
	t_token	*actual;

	new = ft_calloc(1, sizeof(t_token));
	new->word = ft_substr(line, i, token_size);
	new->next = NULL;
	if (*token == NULL)
		*token = new;
	else
	{
		actual = *token;
		while (actual->next != NULL)
			actual = actual->next;
		actual->next = new;
	}
}

/*void ft_erase_node(t_token **token) {
    t_token *tmp = *token;
    t_token *prev = NULL;
    while (tmp) {
        if (tmp->word == NULL || tmp->word[0] == '\0') {
            t_token *to_free = tmp;
            tmp = tmp->next;
            if (prev) prev->next = tmp;
            else *token = tmp;
            free(to_free->word);
            free(to_free);
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}*/