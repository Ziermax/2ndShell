/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  next.c                                               :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 15:25:15 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 16:39:03 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*next_simple(char *str)
{
	if (!str)
		return (NULL);
	while (*str && !ft_isspace(*str))
		++str;
	return (str);
}
