/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  main.c                                               :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/04/29 15:50:48 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/04/29 16:09:42 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

int	minishell(char *line)
{
	//t_token		a_ti;
	//t_command	oritos;
	//t_execute	no_existe;
	
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

int	main(void)
{
	char	*line;
	int		ex_status = 0;

	while (1)
	{
		write(1, "Promting (write whatever): ", 27);
		line = get_next_line(0);
		if (!line)
			continue ;
		if (!ft_strncmp("exit", line, 4) || !ft_strncmp("adios" , line, 5))
			return (free(line), ex_status);
		dprintf(2, "Line reached is: \n%s\n", line);
		dprintf(2, "Minishell process:\n\n");
		ex_status = minishell(line);
		free(line);
	}
}
