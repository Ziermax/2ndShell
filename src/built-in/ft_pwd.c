/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  ft_pwd.c                                             :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 02:26:06 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 02:26:08 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "../../inc/libft.h"
#include "../../inc/envairoment.h"
/*
pwd: pwd [-LPW]
    Print the name of the current working directory.

    Options:
      -L        print the value of $PWD if it names the current working
                directory
      -P        print the physical directory, without any symbolic links
      -W        print the Win32 value of the physical directory

    By default, `pwd' behaves as if `-L' were specified.

    Exit Status:
    Returns 0 unless an invalid option is given or the current directory
    cannot be read.*/

int	ft_pwd(char **argv, t_shell *shell)
{
	char	*cwd;

	(void)shell;
	if (!argv || !*argv)
		return (fd_printf(2, "pwd: bad argument\n"), 3);
	++argv;
	if (!ft_strncmp("--help", *argv, 8))
		return (fd_printf(2, "pwd: no help provided\n"), 2);
	if (argv[0] && argv[0][0] == '-' && argv[0][1])
		return (fd_printf(2, SHELL ": pwd is not accepting options today\n"),
			2);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (fd_printf(2, "pwd: %s\n", strerror(errno)), 1);
	fd_printf(1, "%s\n", cwd);
	free(cwd);
	return (0);
}
