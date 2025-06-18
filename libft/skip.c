/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  skip.c                                               :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/18 23:13:11 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 00:45:39 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*no_skip(char *str)
{
	return (*str);
}

char	*skip_space(char *str)
{
	if (!str)
		return (NULL);
	while (ft_isspace(*str))
		++str;
	return (str);
}
