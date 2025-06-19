#include "struct.h"

void	ft_index(t_token *token)
{
	t_token	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_count_pipes(t_token *token)
{
	t_token	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (tmp)
	{
		if (tmp->type == T_PIPE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	get_last(t_token *token, int start)
{
	t_token	*tmp;
	int		last_index;

	last_index = -1;
	tmp = token;
	while (tmp && tmp->next)
	{
		if (tmp->type == T_PIPE && tmp->index > start)
			return (tmp->index - 1);
		tmp = tmp->next;
	}
	last_index = tmp->index;
	return (last_index);
}
