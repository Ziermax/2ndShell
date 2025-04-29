/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mainuse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:58:50 by gergarci          #+#    #+#             */
/*   Updated: 2024/01/26 20:23:51 by gergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = -1;
	while (s2[++j])
		s3[i + j] = s2[j];
	return (s3);
}

//Or as:
	//ft_memcpy(s3, s1, s1len + 1);
	//ft_strlcat(s3, s2, s1len + s2len + 1);

void	*ft_calloc(size_t count, size_t size)
{
	void	*memo;
	size_t	howfull;

	howfull = count * size;
	memo = malloc(howfull);
	if (!memo)
		return (NULL);
	ft_bzero(memo, howfull);
	return (memo);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*stemp;

	stemp = (unsigned char *) s;
	while (n)
	{
		*stemp = '\0';
		n--;
		stemp++;
	}
}
