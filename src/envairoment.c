#include <unistd.h>
#include "../inc/struct.h"
#include "../inc/libft.h"

void	print_env(void *env)
{
	t_env	*aux;

	if (!env)
		return ;
	aux = env;
	fd_printf(1, "I'm: %p\n | key:%s\n | value:%s\n | next: %p\n",
			aux, aux->key, aux->value, aux->next);
}

void	delete_env(void *env)
{
	t_env	*aux;

	if (!env)
		return ;
	aux = env;
	free(aux->key);
	free(aux->value);
}

t_env	*find_key(char *key, t_env *env)
{
	int	len;

	if (!key)
		return (NULL);
	len = ft_strlen(key);
	while (env)
	{
		if (!ft_strncmp(key, env->key, len))
			return (env);
		env = env->next;
	}
	return (NULL);
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
	while (prev->next && prev->next != aux)
		prev = prev->next;
	if (!prev->next)
		return ;
	prev->next = aux->next;
	delete_env(aux);
	free(aux);
}

#include <stdio.h>
char	*find_value(char *key, t_env *env)
{

	env = find_key(key, env);
	if (!env)
		return (NULL);
	return (env->value);
}

int	copy_value(char *key, char **value_box, t_env *env)
{
	char	*value;

	if (!key || !value_box)
		return (-1);
	*value_box = NULL;
	if (!env)
		return (0);
	value = find_value(key, env);
	if (!value)
		return (0);
	value = ft_strdup(value);
	if (!value)
		return (-1);
	*value_box = value;
	return (0);
}

t_env	*change_value(char *key, char *value, t_env *env)
{
	t_env	*aux;

	if (!key)
		return (NULL);
	aux = find_key(key, env);
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
	aux = change_value(key, value, *list);
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
	aux = find_key(key, *list);
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

t_env	*create_list(char **envp)
{
	t_env	*env;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		if (ft_split_in_two(envp[i], '=', &key, &value) == -1)
			return (lst_clear(&env, delete_env), NULL);
		if (add_value(key, value, &env) == NULL)
			return (free(key), free(value), lst_clear(&env, delete_env), NULL);
		++i;
	}
	return (env);
}

char	**create_env(t_env *env)
{
	char	**envp;
	int		len;
	int		i;

	len = lst_size(env);
	envp = malloc(sizeof(char *) * (len + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (i < len && env)
	{
		envp[i] = ft_threejoin(env->key, "=", env->value);
		if (!envp[i])
			return (free_array(envp), NULL);
		env = env->next;
		++i;
	}
	envp[i] = NULL;
	return (envp);
}
