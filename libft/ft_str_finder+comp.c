/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_finder+comp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:58:50 by gergarci          #+#    #+#             */
/*   Updated: 2024/08/05 19:21:35 by gergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	let;
	int		pos;

	pos = 0;
	let = (char) c;
	while (s[pos] != '\0' && s[pos] != let)
		pos++;
	if (s[pos] == let)
		return ((char *) &s[pos]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	let;
	int		pos;

	pos = 0;
	let = (char) c;
	while (s[pos] != '\0')
		pos++;
	if (c == '\0')
		return ((char *) &s[pos]);
	while (pos >= 0)
	{
		if (s[pos] == let)
			return ((char *) &s[pos]);
		pos--;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (needle[x] == 0)
		return ((char *) haystack);
	while (haystack[x] != '\0' && x < len)
	{
		y = 0;
		while (haystack[x + y] == needle[y] && (x + y) < len)
		{
			y++;
			if (needle[y] == '\0')
				return ((char *) &haystack[x]);
		}
		x++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1temp;
	unsigned char	*s2temp;

	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	s1temp = (unsigned char *) s1;
	s2temp = (unsigned char *) s2;
	i = 0;
	while (i < n - 1 && s1temp[i] != '\0' && s1temp[i] == s2temp[i])
		i++;
	return (s1temp[i] - s2temp[i]);
}
