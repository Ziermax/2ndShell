#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join;
	int		len1;
	int		len2;
	int		i;

	if (!str1 && !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!len1 && !len2)
		return (ft_calloc(sizeof(char), 1));
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < len1)
		join[i] = str1[i];
	while (i < len1 + len2)
	{
		join[i] = str2[i - len1];
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_threejoin(char *str1, char *str2, char *str3)
{
	char	*join;
	int		len1;
	int		len2;
	int		len3;
	int		i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	len3 = ft_strlen(str3);
	if (!len1 && !len2 && !len3)
		return (NULL);
	join = malloc(sizeof(char) * (len1 + len2 + len3 + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < len1)
		join[i] = str1[i];
	i -= 1;
	while (++i < len1 + len2)
		join[i] = str2[i - len1];
	i -= 1;
	while (++i < len1 + len2 + len3)
		join[i] = str3[i - len1 - len2];
	join[i] = '\0';
	return (join);
}

char	*ft_splitjoin(char	**split)
{
	char	*join;
	int		len;
	int		i;
	int		j;
	int		k;

	if (!split)
		return (NULL);
	len = ft_split_charlen(split);
	join = malloc(sizeof(char *) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (split[i] && j < len)
	{
		k = 0;
		while (split[i][k] && j < len)
			join[j++] = split[i][k++];
		++i;
	}
	join[len] = '\0';
	join[j] = '\0';
	return (join);
}

char	*ft_multiplejoin(int num, ...)
{
	va_list	ap;
	char	**multiple;
	char	*join;
	int		i;

	if (num <= 0)
		return (NULL);
	multiple = malloc(sizeof(char *) * (num + 1));
	if (!multiple)
		return (NULL);
	va_start(ap, num);
	i = 0;
	while (i < num)
		multiple[i++] = va_arg(ap, char *);
	multiple[i] = NULL;
	va_end(ap);
	join = ft_splitjoin(multiple);
	free(multiple);
	return (join);
}

int	ft_split_charlen(char **split)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (split[i])
		len += ft_strlen(split[i++]);
	return (len);
}

/*
#include <stdio.h>
int	main(int argc, char **argv, char **envp)
{
	//char	split[4][] = {"Hola ", "Mundo ", "Tierra", NULL};
	char	*str;

	(void)argc;
	(void)envp;
	//str = ft_splitjoin(split);
	str = ft_splitjoin(argv);
	if (!str)
		return (perror("Split"), 1);
	printf("Split res: \"%s\"\n", str);
	free(str);
}*/
