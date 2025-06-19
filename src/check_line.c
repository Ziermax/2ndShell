/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  check_line.c                                         :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 10:43:57 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 13:22:49 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	check_line(char *str)
{
	int	quote;
	int	i;

	/*	*
	 *	Check for unclose quote
	 */
	i = -1;
	quote = 0;
	while (str[++i])
	{
		if (str[i] != '\"' && str[i] != '\'')
			continue ;
		//dprintf(2, "I'm in this: %c\n", str[i]);
		quote = str[i++];
		while (str[i] && str[i] != quote)
			++i;
		if (str[i] == quote)
			quote = 0;
		if (!str[i])
			break ;
	}
	//Borrar esto quita el '\n' para que parezca readline
	i = 0;
	while (str[i])
		++i;
	if (i && str[i - 1] == '\n')
		str[i - 1] = '\0';
	if (quote)
		return (-1);
	return (0);
}
