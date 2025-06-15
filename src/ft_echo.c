#include "../inc/libft.h"

int	is_newline_on(char **argv)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		str = argv[i];
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

int	ft_echo(char **argv, t_shell *shell)
{
	int	nl_flag;
	int	i;

	(void)shell;
	if (!argv || !*argv)
		return (ft_printf(2, "echo: bad argument\n"), 3);
	nl_flag = is_newline_on(++argv);
	i = nl_flag;
	while (argv[i])
	{
		ft_printf(1, "%s", argv[i]);
		if (argv[i + 1])
			ft_printf(1, " ");
		++i;
	}
	if (nl_flag)
		ft_printf(1, "\n");
	return (0);
}
