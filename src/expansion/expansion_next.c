/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  expansion_next.c                                     :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 02:44:55 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 10:38:17 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	is_varchar(int c)
{
	return (ft_isalnum(c) || c == '_');
}

int	is_varstart(char c)
{
	return (ft_isalpha(c) || c == '_' || c == '?');
}

char	*next_word(char *str)
{
	if (!str)
		return (NULL);
	while (!ft_isspace(*str))
		++str;
	return (str);
}

		//&& ((is_varchar(str[1]) && !ft_isdigit(str[1])) || str[1] == '?'))
			//	&& ((is_varchar(str[1]) && !ft_isdigit(str[1]))
			//	|| str[1] == '?'))
char	*next_var(char *str)
{
	if (!str)
		return (NULL);
	if (str[0] == '$' && is_varstart(str[1]))
	{
		str++;
		if (*str == '?')
			return (str + 1);
		while (is_varchar(*str))
			str++;
		return (str);
	}
	while (*str)
	{
		if (str[0] == '$' && is_varstart(str[1]))
			break ;
		str++;
	}
	return (str);
}

char	*next_quote(char *str)
{
	int	quote;

	if (!str)
		return (NULL);
	quote = 0;
	if (*str == '\"' || *str == '\'')
		quote = *(str++);
	if (quote)
	{
		while (*str)
			if (*(str++) == quote)
				break ;
	}
	else
		while (*str && *str != '\'' && *str != '\"')
			++str;
	return (str);
}
