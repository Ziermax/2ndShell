/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*  array.c                                              :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*  By: mvelazqu <mvelazqu@student.42barcelona.c     +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*  Created: 2025/06/18 23:09:02 by mvelazqu            #+#    #+#            */
/*  Updated: 2025/06/18 23:12:26 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

void	free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static int	count_words(
		char *str,
		char *(*skip_separator)(char *),
		char *(*next_word)(char *)
		) {
	int	words;

	words = 0;
	while (*str)
	{
		str = skip_separator(str);
		if (!*str)
			return (words);
		words++;
		str = next_word(str);
	}
	return (words);
}

static char	*get_word(
		char **str,
		char *(*skip_separator)(char *),
		char *(*next_word)(char *)
		) {
	char	*word;
	char	*aux;
	int		len;
	int		i;

	*str = skip_separator(*str);
	aux = next_word(*str);
	len = aux - *str;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	aux = *str;
	i = 0;
	while (i < len)
		word[i++] = *aux++;
	word[i] = '\0';
	*str = aux;
	return (word);
}

char	**ultra_split(char *str, char *(*skip)(char *), char *(*next)(char *))
{
	char	**split;
	int		words;
	int		i;

	if (!str)
		return (NULL);
	words = count_words(str, skip, next);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		split[i] = get_word(&str, skip, next);
		if (!split[i++])
			return (free_split(split), NULL);
	}
	split[i] = NULL;
	return (split);
}
