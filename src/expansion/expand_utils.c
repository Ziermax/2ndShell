/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  expand_utils.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:39:19 by mvelazqu          #+#    #+#             */
/*  Updated: 2025/06/19 20:32:42 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../inc/expand.h"

int	ft_isonly_asterisk(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*(str++) != '*')
			return (0);
	return (1);
}

int	ft_isasterisk(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\\' && str[1])
			str += 2;
		if (!*str)
			break ;
		if (*str == '*')
			return (1);
		str++;
	}
	return (0);
}

int	xp_ft_isvarchar(int c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*remove_quotes(char *string)
{
	char	*tmp;
	int		len;
	int		quote;

	if (!string)
		return (NULL);
	if (*string != '\'' && *string != '\"')
		return (ft_strdup(string));
	quote = *string;
	len = ft_strlen(string);
	if (len < 2)
		return (ft_calloc(sizeof(char), 1));
	if (string[len - 1] == '\'' || string[len - 1] == '\"')
		len -= 2;
	else
		len -= 1;
	string = ft_substr(string, 1, len);
	if (!string)
		return (NULL);
	if (quote == '\'')
		tmp = add_slash(string, " *\"'");
	else
		tmp = add_slash(string, " *\"'");
	return (free(string), tmp);
}

char	*remove_quotes_string(char *string)
{
	char	**split_string;
	char	**tmp;

	split_string = ultra_split(string, no_skip, xp_next_string);
	if (!split_string)
		return (NULL);
	tmp = split_for_each(split_string, remove_quotes);
	free_array(split_string);
	if (!tmp)
		return (NULL);
	split_string = tmp;
	string = ft_splitjoin(split_string);
	free_array(split_string);
	return (string);
}
