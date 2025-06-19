/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  expansion.c                                          :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/19 02:45:04 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/19 05:07:33 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/envairoment.h"
#include "../inc/expansion.h"

static char	*expand_var(char *str, t_shell *shell)
{
	char	*expansion;

	if (*str == '$')
		++str;
	if (*str == '?')
		return (ft_itoa(shell->status));
	if (copy_value(str, &expansion, shell->env) == -1)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	return (str);
}

static char	**none_quote_case(char *str, t_shell *shell)
{
	char	**split_var;
	int		i;

	split_var = ultra_split(str, no_skip, next_var);
	if (!split_var)
		return (NULL);
	i = -1;
	while (split_var[++i])
	{
		if (split_var[i][0] != '$' || !is_varstart(split_var[i][1]))
			continue ;
		str = expand_var(split_var[0], shell);
		if (!str)
			return (free_array(split_var), NULL);
		free(split_var[++i]);
		split_var[i] = str;
	}
	str = ft_splitjoin(split_var);
	free_array(split_var);
	split_var = ultra_split(str, skip_space, next_word);
	free(str);
	return (split_var);
}

static char	**double_quote_case(char *str, t_shell *shell)
{
	char	**split_var;
	int		i;

	str = ft_strtrim(str, "\"");
	if (!str)
		return (NULL);
	split_var = ultra_split(str, no_skip, next_var);
	free(str);
	if (!split_var)
		return (NULL);
	i = -1;
	while (split_var[++i])
	{
		if (split_var[i][0] != '$' || !is_varstart(split_var[i][1]))
			continue ;
		str = expand_var(split_var[0], shell);
		if (!str)
			return (free_array(split_var), NULL);
		free(split_var[i]);
		split_var[i] = str;
	}
	str = ft_splitjoin(split_var);
	free_array(split_var);
	split_var = add_dir(NULL, str);
	if (!split_var)
		return (free(str), NULL);
	return (split_var);
}

static char	**single_quote_case(char *str)
{
	char	**ret;

	ret = malloc(sizeof(char *) * 2);
	if (!ret)
		return (NULL);
	str = ft_strtrim(str, "'");
	if (!str)
		return (free(ret), NULL);
	ret[0] = str;
	ret[1] = NULL;
	return (ret);
}

char	**expand_str(char *str, t_shell *shell)
{
	char	**split_quote;
	char	**expansion;
	char	**aux;
	int		i;

	if (!str || !shell)
		return (NULL);
	split_quote = ultra_split(str, no_skip, next_quote);
	if (!split_quote)
		return (NULL);
	i = 0;
	expansion = NULL;
	while (split_quote[i])
	{
		if (split_quote[i][0] == '\'')
			aux = single_quote_case(split_quote[i]);
		else if (split_quote[i][0] == '\"')
			aux = double_quote_case(split_quote[i], shell);
		else
			aux = none_quote_case(split_quote[i], shell);
		if (!aux)
			return (free_array(split_quote), NULL);
		expansion = add_array(expansion, aux);
		if (!expansion)
			return (free_array(aux), free_array(split_quote), NULL);
		++i;
	}
	return (free_array(split_quote), expansion);
}
