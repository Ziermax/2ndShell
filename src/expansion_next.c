char	*next_quote(char *str)
{
	int	quote;

	if (!str)
		return (NULL);
	quote = 0;
	if (*str == '\"' || *str == '\'')
		quote = *(str++);
	if (quote)
	{
		while (*str)
			if (*(str++) == quote)
				break ;
	}
	else
		while (*str && *str != '\'' && *str != '\"')
			++str;
	return (str);
}
