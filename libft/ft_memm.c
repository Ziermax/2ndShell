/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:22:50 by gergarci          #+#    #+#             */
/*   Updated: 2024/01/30 17:22:29 by gergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	kar;
	unsigned char	*stemp;
	int				pos;

	kar = (unsigned char) c;
	stemp = (unsigned char *) s;
	pos = 0;
	while (n--)
	{
		if (stemp[pos] == kar)
			return (&stemp[pos]);
		pos++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1temp;
	unsigned char	*s2temp;
	size_t			i;

	s1temp = (unsigned char *) s1;
	s2temp = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1temp[i] == s2temp[i])
		i++;
	return (s1temp[i] - s2temp[i]);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;

	if (!dst && !src)
		return (0);
	else
	{
		dtemp = (unsigned char *) dst;
		stemp = (unsigned char *) src;
		while (n--)
			*dtemp++ = *stemp++;
		return (dst);
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dtemp;
	char	*stemp;

	dtemp = (char *) dst;
	stemp = (char *) src;
	if (!dst && !src)
		return (0);
	else
	{
		if (dst <= src)
		{
			while (len--)
				*dtemp++ = *stemp++;
		}
		else if (dst > src)
		{
			dtemp += len -1;
			stemp += len -1;
			while (len--)
				*dtemp-- = *stemp--;
		}
		return (dst);
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*btemp;

	btemp = (unsigned char *) b;
	while (len)
	{
		*btemp = c;
		len--;
		btemp++;
	}
	return (b);
}
