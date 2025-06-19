/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  expand_env.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:24:16 by mvelazqu          #+#    #+#             */
/*  Updated: 2025/06/19 21:19:25 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../inc/expand.h"
#include "../../inc/envairoment.h"

//Esto se cambia a lo mio
//static char	*(char *key, t_shell *shell)
static char	*search_envvar(char *key, t_shell *shell)
{
	char	*expansion;

//	if (*key == '$')
//		++key;
	if (*key == '?')
		return (ft_itoa(shell->status));
	if (copy_value(key, &expansion, shell->env) == -1)
		return (NULL);
	if (!expansion)
		expansion = ft_strdup("");
	return (expansion);
}
	/*
	char	*value;
	int		len;

	if (!key)
		return (NULL);
	if (*key == '?')
		return (ft_itoa(shell->status));
	if (!shell->env)
		return (ft_strdup(""));
	key = ft_strjoin(key, "=");
	if (!key)
		return (NULL);
	len = ft_strlen(key);
	value = search_word_in_split(key, shell->env, len);
	if (!value)
		return (free(key), ft_strdup(""));
	return (free(key), ft_strdup(&value[len]));
}*/

static char	*expand_var(char *string, void *shell)
{
	char	*expanded;
	char	*slashed;

	if (!string || !shell)
		return (NULL);
	if (*string != '$' || (!xp_ft_isvarchar(string[1]) && string[1] != '?'))
		return (ft_strdup(string));
	expanded = search_envvar(&string[1], shell);
	if (!expanded)
		return (NULL);
	slashed = add_slash(expanded, "*\\\"\'");
	free(expanded);
	return (slashed);
}

static char	*expand_env_string(char *string, void *shell)
{
	char	**split_string;
	char	**tmp;

	if (!string || !shell)
		return (NULL);
	if (*string == '\'')
		return (ft_strdup(string));
	split_string = ultra_split(string, no_skip, xp_next_var);
	if (!split_string)
		return (NULL);
	tmp = split_for_each_aux(split_string, shell, expand_var);
	free_array(split_string);
	if (!tmp)
		return (NULL);
	split_string = tmp;
	string = ft_splitjoin(split_string);
	free_array(split_string);
	return (string);
}

char	**expand_envvar(char *string, t_shell *shell)
{
	char	**split_string;
	char	**tmp;

	split_string = ultra_split(string, no_skip, xp_next_string);
	if (!split_string)
		return (NULL);
	tmp = split_for_each_aux(split_string, shell, expand_env_string);
	free_array(split_string);
	if (!tmp)
		return (NULL);
	split_string = tmp;
	string = ft_splitjoin(split_string);
	free_array(split_string);
	if (!string)
		return (NULL);
	split_string = ultra_split(string, skip_space, xp_next_word);
	free(string);
	return (split_string);
}
