/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:22:50 by gergarci          #+#    #+#             */
/*   Updated: 2024/01/30 17:22:29 by gergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	if (s && fd > 0)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
			write(fd, &s[i++], 1);
		write(fd, "\n", 1);
	}
}

static void	print_num(int nb2, int fd2)
{
	int		nums[10];
	int		i;
	char	printable;

	i = 0;
	while (nb2 > 0)
	{
		nums[i] = nb2 % 10;
		nb2 = nb2 / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		printable = nums[i] + 48;
		write(fd2, &printable, 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0 && n > -2147483648)
	{
		write(fd, "-", 1);
		print_num(n * -1, fd);
	}
	else if (n > 0 && n <= 2147483647)
		print_num(n, fd);
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
		write(fd, "0", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	if (s && fd > 0)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
			write(fd, &s[i++], 1);
	}
}

/*PUTSTR RECURSIVE VS
void	putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return;
	if (*s != '\0')
	{
		write(fd, s, 1); buf: n:
		putstr_fd(s + 1, fd); s:
	}
}*/