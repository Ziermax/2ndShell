/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  ft_export.c                                          :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 02:25:36 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 02:25:37 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include "../../inc/libft.h"
#include "../../inc/envairoment.h"
/*
export: export [-fn] [name[=value] ...] or export -p
    Set export attribute for shell variables.

    Marks each NAME for automatic export to the environment of subsequently
    executed commands.  If VALUE is supplied, assign VALUE before exporting.

    Options:
      -f        refer to shell functions
      -n        remove the export property from each NAME
      -p        display a list of all exported variables and functions

    An argument of `--' disables further option processing.

    Exit Status:
    Returns success unless an invalid option is given or NAME is invalid.*/

static int	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) || str[i] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) || str[i] != '_')
			return (0);
		if (str[i] == '+' && str[i + 1] == '=')
			continue ;
		++i;
	}
	return (1);
}

static int	get_key_value(char *str, char **key, char **value)
{
	char	*equal;

	equal = ft_strchr(str, '=');
	if (equal)
		*key = ft_substr(str, START, equal - str);
	else
		*key = ft_strdup(str);
	if (!*key)
		return (1);
	if (equal)
	{
		*value = ft_strdup(equal + 1);
		if (!*value)
			return (free(*key), 1);
	}
	else
		*value = NULL;
	return (0);
}

static int	add_export(char *str, t_env **env)
{
	t_env	*aux;
	char	*equal;
	char	*key;
	char	*value;

	if (!is_valid_identifier(str))
		return (fd_printf(2, "export: `%s': not a valid identifier\n", str), 1);
	if (get_key_value(str, &key, &value))
		return (fd_printf(2, "export: %s\n", strerror(errno)), 3);
	equal = ft_strchr(str, '=');
	if (equal && *(equal - 1) == '+')
		aux = expand_value(key, value, env);
	else
		aux = add_value(key, value, env);
	if (!aux)
		return (free(key), free(value),
			fd_printf(2, "export: %s\n", strerror(errno)), 3);
	return (0);
}

void	print_export(t_env *env)
{
	while (env)
	{
		fd_printf(1, "meclare -x %s", env->key);
		if (env->value)
			fd_printf(1, "=\"%s\"", env->value);
		fd_printf(1, "\n");
		env = env->next;
	}
}

int	ft_export(char **argv, t_shell *shell)
{
	int	ret;
	int	f_ret;
	int	i;

	if (!argv || !*argv)
		return (fd_printf(2, "export: bad argument\n"), 3);
	++argv;
	if (!ft_strncmp("--help", *argv, 8))
		return (fd_printf(2, "export: no help provided\n"), 2);
	if (!argv[0])
		return (print_export(shell->env), 0);
	if (argv[0][0] == '-' && argv[0][1])
		return (fd_printf(2, SHELL ": export is not accepting options today\n"),
			2);
	i = 0;
	f_ret = 0;
	while (argv[i])
	{
		ret = add_export(argv[i], &shell->env);
		if (ret && !f_ret)
			f_ret = ret;
		++i;
	}
	return (f_ret);
}
