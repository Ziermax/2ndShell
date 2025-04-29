/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cpy+gnrte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:58:50 by gergarci          #+#    #+#             */
/*   Updated: 2024/01/26 20:23:51 by gergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	i;
	size_t	finlen;

	dlen = 0;
	i = 0;
	finlen = 0;
	while (dst[dlen] != '\0')
		dlen++;
	while (src[finlen] != '\0')
		finlen++;
	if (dstsize <= dlen)
		finlen += dstsize;
	else
		finlen += dlen;
	while (src[i] != '\0' && (dlen + 1) < dstsize)
	{
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (finlen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*s1dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	s1dup = (char *) malloc(len * sizeof(char) + 1);
	if (!s1dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		s1dup[i] = s1[i];
		i++;
	}
	s1dup[i] = '\0';
	return (s1dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = ft_strlen(s);
	if (start <= (unsigned int) i)
	{
		if (i - start < len)
			len = i - start;
		substr = (char *)malloc((len + 1) * sizeof(char));
		if (substr == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			substr[i] = s[i + start];
			i++;
		}
	}
	else
		return (ft_calloc(1, sizeof(char)));
	substr[i] = '\0';
	return (substr);
}
