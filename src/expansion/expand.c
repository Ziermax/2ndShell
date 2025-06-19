/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  expand.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:19:13 by mvelazqu          #+#    #+#             */
/*  Updated: 2025/06/19 21:21:09 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft/libft.h"
#include "../../inc/expand.h"

static char	**expand_asterisk_aux(char *string, void *null)
{
	char	**expansion;

	(void)null;
	expansion = expand_asterisk(string);
	if (!expansion)
		return (NULL);
	if (ft_isasterisk(string) && *expansion)
		return (expansion);
	free_array(expansion);
	string = remove_slash(string, "");
	if (!string)
		return (NULL);
	expansion = add_dir(NULL, string);
	if (!expansion)
		return (NULL);
	return (expansion);
}

char	**expand_string(char *string, void *shell)
{
	char	**expansion;
	char	**aux;

	string = remove_slash(string, "\\\"'* ");
	if (!string)
		return (NULL);
	aux = expand_envvar(string, shell);
	free(string);
	if (!aux)
		return (NULL);
	expansion = split_for_each(aux, remove_quotes_string);
	free_array(aux);
	if (!expansion)
		return (NULL);
	aux = ultra_split_for_each_aux(expansion, NULL, expand_asterisk_aux);
	free_array(expansion);
	if (!aux)
		return (NULL);
	expansion = split_for_each_aux(aux, "", remove_slash);
	free_array(aux);
	return (expansion);
}

#include <stdio.h>
char	**expand_array(char **split_string, t_shell *shell)
{
	char	**expansion;

	expansion = ultra_split_for_each_aux(split_string, shell, expand_string);
	free_array(split_string);
	if (!expansion)
		return (NULL);
//	for (int i = 0; expansion[i]; ++i)
//	{
//		printf("expansion[%d]: %s\n", i, expansion[i]);
//	}
	return (expansion);
}
