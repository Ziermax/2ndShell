/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:22:50 by gergarci          #+#    #+#             */
/*   Updated: 2024/01/30 17:22:29 by gergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	i;

	i = 0;
	if (c >= 48 && c <= 57)
		i = 1;
	else if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		i = 1;
	else
		i = 0;
	return (i);
}

int	ft_isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
