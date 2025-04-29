/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:50:45 by gergarci          #+#    #+#             */
/*   Updated: 2024/07/25 16:24:24 by gergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_write_pstr(char *c, int len, int *ch_print)
{
	if (*ch_print == -1)
		return ;
	else if (write(1, c, len) < 0)
		*ch_print = -1;
	else
		*ch_print += len;
}

void	ft_print_char(char c, int *ch_print)
{
	if (*ch_print == -1)
		return ;
	else if (write(1, &c, 1) < 0)
		*ch_print = -1;
	else
		*ch_print += 1;
}

void	ft_print_string(char *str, int *ch_print)
{
	if (!str)
		ft_write_pstr("(null)", 6, ch_print);
	else if (str)
		ft_write_pstr(str, ft_strlen(str), ch_print);
}
