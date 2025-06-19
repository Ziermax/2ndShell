/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  main.c                                               :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/04/29 15:50:48 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 15:08:27 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>// dprintf()
#include <unistd.h>
#include "../libft/libft.h"
#include "../inc/builtins.h"
#include "../inc/minishell.h"

/*
int	execute_builtin(t_cmd *command, t_shell *shell)
{
	if (echo)
		return (ft_echo(command->argv, shell));
}

int	execute(t_cmd *command, t_shell *shell)
{
	char	**env;

	if (is_buitlin(command->path))
		execute_builtin(shell);
	//env = generate_env(shell->env);
	execve(command->argv, command->path, env);
}*/

int	minishell(char *line, t_shell *shell)
{
	(void)shell;

	fd_printf(1, "This is the line: %s\n", line);
	return (/*EL NUMERO DEL EXIT STATUS*/ 0);
}

static void	read_shell(t_shell *shell)
{
	char	*line;

	while (!shell->finished)
	{
		//line = getline(SHELL ": ");
		write(1, "Promting (write whatever): ", 27);//	Reemplazar readline
		line = get_next_line(0);//						Reemplazar readline
		if (!line)
			return ((void)ft_exit((void *)1, shell));
		if (check_line(line) == -1)
			ft_perro("Close da quotes pal", NULL);
		else
			shell->status = minishell(line, shell);
		//if (line[0])
		//	add_history(line);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argv;
	(void)argc;
	//envp = argv;
	if (argc != 1)
		return (ft_perro(SHELL " isn't accepting arguments pal", NULL), 3);
	if (init_shell(&shell, envp) == -1)
		return (ft_perro(SHELL ": initing shell", NULL), 3);
	lst_for_each(shell.env, print_env);
	read_shell(&shell);
	destroy_shell(&shell);
	return (shell.status);
}
