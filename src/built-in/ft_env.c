/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  ft_env.c                                             :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 02:24:24 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 20:11:20 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/envairoment.h" 
#include "../../inc/libft.h"
/*
Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]
Set each NAME to VALUE in the environment and run COMMAND.

Mandatory arguments to long options are mandatory for short options too.
  -i, --ignore-environment  start with an empty environment
  -0, --null           end each output line with NUL, not newline
  -u, --unset=NAME     remove variable from the environment
  -C, --chdir=DIR      change working directory to DIR
  -S, --split-string=S  process and split S into separate arguments;
                        used to pass multiple arguments on shebang lines
      --block-signal[=SIG]    block delivery of SIG signal(s) to COMMAND
      --default-signal[=SIG]  reset handling of SIG signal(s) to the default
      --ignore-signal[=SIG]   set handling of SIG signals(s) to do nothing
      --list-signal-handling  list non default signal handling to stderr
  -v, --debug          print verbose information for each processing step
      --help     display this help and exit
      --version  output version information and exit

A mere - implies -i.  If no COMMAND, print the resulting environment.

SIG may be a signal name like 'PIPE', or a signal number like '13'.
Without SIG, all known signals are included.  Multiple signals can be
comma-separated.

GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
Report any translation bugs to <https://translationproject.org/team/>
Full documentation <https://www.gnu.org/software/coreutils/env>
or available locally via: info '(coreutils) env invocation'*/

static void	print_env_aux(t_env	*env)
{
	while (env)
	{
		if (env->value)
			fd_printf(1, "%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

int	ft_env(char **argv, t_shell *shell)
{
	if (!argv || !shell)
		return (2);
	++argv;
	if (!argv[0])
		return (print_env_aux(shell->env), 0);
	if (argv[0][0] == '-')
		return (fd_printf(2, SHELL ": env is not accepting options today\n"),
			3);
	fd_printf(2, "env: '%s': We are not launching another program pal\n", *argv);
	return (3);
}
