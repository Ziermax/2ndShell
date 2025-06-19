/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  ft_echo.c                                            :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 02:24:29 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 02:24:31 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/envairoment.h"

int	is_newline_on(char **argv)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		str = argv[i];
		j = 0;
		if (str[j++] != '-')
			break ;
		while (str[j] == 'n')
			++j;
		if (str[j])
			break ;
		++i;
	}
	return (i);
}

int	ft_echo(char **argv, t_shell *shell)
{
	int	nl_flag;
	int	i;

	(void)shell;
	if (!argv || !*argv)
		return (fd_printf(2, "echo: bad argument\n"), 3);
	nl_flag = is_newline_on(++argv);
	i = nl_flag;
	while (argv[i])
	{
		fd_printf(1, "%s", argv[i]);
		if (argv[i + 1])
			fd_printf(1, " ");
		++i;
	}
	if (nl_flag)
		fd_printf(1, "\n");
	return (0);
}
