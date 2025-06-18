#include <limits.h>
#include "../../inc/libft.h"
#include "../../inc/envairoment.h"

static int	exit_number(char *str)
{
	unsigned long	num;
	int				sign;
	int				i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	sign = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = 1;
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num += str[i++] - '0';
		if ((num > LONG_MAX && !sign)
				|| (num > ((unsigned long)1 + LONG_MAX) && sign))
			break ;
	}
	while (ft_isspace(str[i]))
		++i;
	if (str[i])
		return (-1);
	return ((long)num * sign);
}

int	ft_exit(char **argv, t_shell *shell)
{
	int	status;

	if (!argv || !*argv)
		return (fd_printf(2, "exit: bad argument\n"), 3);
	++argv;
	shell->finished = 1;
	fd_printf(2, "exit\n");
	if (!*argv)
		return (shell->status);
	status = exit_number(argv[0]);
	if (status == -1)
		return (fd_printf(2, SHELL ": exit: %s: numeric argument required\n",
					argv[0]), 2);
	if (argv[1])
		return (fd_printf(2, SHELL ":exit: too many arguments\n"),
				shell->finished = 0, 1);
	return (status);
}
