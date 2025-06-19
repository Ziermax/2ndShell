/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  main.c                                               :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/04/29 15:50:48 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 02:29:24 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../inc/struct.h"

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
	//t_token		a_ti;
	//t_command	oritos;
	//t_execute	no_existe;
	(void)shell;
	(void)line;
	dprintf(2, "Tokenizing (seprar en palabras).\n");
	//a_ti = tokenizar(line);
	dprintf(2, "Commanding (Pasar de palabras a algo mejor).\n");
	//oritos = commanding(a_ti);
	dprintf(2, "Executting (Ejecutar esa estructura de comandos).\n");
	//no_existe = executing(oritos);
	dprintf(2, "Retturning last exit status.\n\n");
	return (/*EL NUMERO DEL EXIT STATUS*/ 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	(void)argc;
	(void)argv;
	//init_shell(&shell);
	shell.finished = 0;
	shell.status = 2;
	shell.envp = envp;
	while (!shell.finished)
	{
		write(1, "Promting (write whatever): ", 27);
		line = get_next_line(0);
		if (!line)
			continue ;
		if (!ft_strncmp("exit", line, 4) || !ft_strncmp("adios", line, 5))
			return (free(line), shell.status);
		dprintf(2, "Line reached is: \n%s\n", line);
		dprintf(2, "Minishell process:\n\n");
		shell.status = minishell(line, &shell);
		free(line);
	}
	//destroy_shell(&shell);
	return (shell.status);
}
