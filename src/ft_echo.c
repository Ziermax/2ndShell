#include "../inc/libft.h"

int	is_newline_on(char **argc)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (argc[i])
	{
		str = argc[i];
		j = 0;
		if (str[j++] != '-')
			break ;
		while (str[j] == 'n')
			++j;
		if (str[j])
			break ;
		++i;
	}
	return (i);
}

int	ft_echo(char **argc, t_env **env)
{
	int	nl_flag;
	int	i;

	(void)env;
	if (!argc)
		return (ft_printf(2, "echo: failed argument creation\n"), 3);
	nl_flag = is_newline_on(++argc);
	i = nl_flag;
	while (argc[i])
	{
		ft_printf(1, "%s", argc[i]);
		if (argc[i + 1])
			ft_printf(1, " ");
		++i;
	}
	if (nl_flag)
		ft_printf(1, "\n");
	return (0);
}
