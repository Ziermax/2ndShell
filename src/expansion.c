#include "../libft/inc/libft.h"

char	**();

//"Hola'Mudno"'HOlaMudno'"$USER" 

char	**split_in_quotes(char *str)
{
	char	**str;
	int	i;

	while (str[i])
	{
		if ()
	}
}

char	**expand_str_array(char **str, t_env *env)
{
}

char	**expand_str(char *str, t_env *env)
{
	char	**split_quote;
	char	**expansion;
	int		i;

	split_quote = ultra_split(str, no_skip, next_quote);
	if (!split_quote)
		return (NULL);
	i = 0;
	while (split_quote[i])
	{
		if (split_quote[i] == '\'')
			expansion = ;
		else if (split_quote[i] == '\"')
			expansion = ;
		else
			expansion = ;
		if (!expansion)
			return (free_array(split_quote), NULL);		
		++i;
	}
}
