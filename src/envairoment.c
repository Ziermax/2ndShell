#include <unistd.h>
#include "../inc/struct.h"
#include "../inc/libft.h"

void	print_env(t_env *env)
{
	if (!env)
		return ;
	ft_printf("2, %s: %s\n", env->key, env->value);
}

void	delete_env(t_env *env)
{
	if (!env)
		return ;
	free(env->key);
	free(env->value);
}

void	erase_key(char *key, t_env **list)
{
	t_env	*aux;
	t_env	*prev;

	if (!list || !key)
		return ;
	aux = find_key(key, *list);
	if (!aux)
		return ;
	prev = *list;
	if (prev == aux)
	{
		delete_env(aux);
		free(aux);
		*list = NULL;
		return ;
	}
	while (prev->next && prev != aux)
		prev = prev->next;
	if (!prev->next)
		return ;
	prev->next = aux->next;
	delete_env(aux);
	free(aux);
}

t_env	*find_key(char *key, t_env *list)
{
	int	len;

	if (!key)
		return (NULL);
	len = ft_strlen(key);
	while (list)
	{
		if (!ft_strncmp(key, list->key, len))
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_env	*change_value(char *key, char *value, t_env *list)
{
	t_env	*aux;

	if (!key)
		return (NULL);
	aux = find_key(key, list);
	if (!aux)
		return (NULL);
	free(aux->value);
	aux->value = value;
	return (aux);
}

t_env	*add_value(char *key, char *value, t_env **list)
{
	t_env	*aux;
	t_env	*tmp;

	if (!list || !key)
		return (NULL);
	aux = change_value(key, value, list);
	if (aux)
		return (free(key), aux);
	tmp = malloc(sizeof(t_env));
	if (!tmp)
		return (NULL);
	tmp->key = key;
	tmp->value = value;
	tmp->next = NULL;
	aux = *list;
	if (!aux)
		return (*list = tmp);
	while (aux->next)
		aux = aux->next;
	aux->next = tmp;
	return (tmp);
}

t_env	*expand_value(char *key, char *append, t_env **list)
{
	t_env	*aux;
	char	*tmp;

	if (!key)
		return (NULL);
	aux = find_key(key, list);
	if (!aux)
		return (add_value(key, append, list));
	tmp = ft_strjoin(aux->value, append);
	if (!tmp)
		return (NULL);
	free(aux->value);
	free(append);
	free(key);
	aux->value = tmp;
	return (aux);
}
