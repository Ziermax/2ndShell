/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_itoas+trim.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:58:50 by gergarci          #+#    #+#             */
/*  Updated: 2025/06/19 05:10:51 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_dig(long n)
{
	int	count;

	count = 0;
	if (n <= 9 && n >= 0)
		return (1);
	else if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		dig;
	long	n2;

	n2 = (long) n;
	dig = count_dig(n2);
	num = (char *) ft_calloc((dig + 1), sizeof(char));
	if (!num)
		return (NULL);
	if (n2 == 0)
		num[0] = '0';
	if (n2 < 0)
	{
		num[0] = '-';
		n2 *= -1;
	}
	dig--;
	while (n2 != 0)
	{
		num[dig] = (n2 % 10) + 48;
		dig--;
		n2 = n2 / 10;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] != '+' && str[i] != '-' && (str[i] < '0' && str[i] > '9'))
		return (num);
	else
	{
		if (str[i] == '-')
			neg = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		return (num * neg);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		first;
	int		last;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	while (last > first && ft_strchr(set, s1[last - 1]))
		last--;
	trim = malloc(sizeof(char) * (last - first + 1));
	if (!trim)
		return (NULL);
	while (first < last)
		trim[i++] = s1[first++];
	trim[i] = '\0';
	return (trim);
}
