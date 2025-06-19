/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  init.c                                               :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 11:53:40 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 11:54:28 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/envairoment.h"

int	init_shell(t_shell *shell, char **envp)
{
	shell->status = 0;
	shell->finished = 0;
	shell->env = create_list(envp);
	if (!shell->envp)
		return (-1);
	return (0);
}

void	destroy_shell(t_shell *shell)
{
	lst_clear(&shell->envp, delete_env);
}
