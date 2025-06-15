#include "../inc/envairoment.h" 
#include "../inc/libft.h"

void	print_env(t_env	*env)
{
	while (env)
	{
		if (env->value)
			ft_printf(1, "%s=%sn", env->key, env->value);
		env = env->next;
	}
}

int	ft_env(char **argv, t_env **env)
{
	if (!argv || !env)
		return (2);
	if (!argv[1])
		return (print_env(*env), 0);
	if (argv[1][0] == '-')
		return (ft_printf(2, SHELL ": env is not accepting options today\n"), 125);
	ft_printf(2, "env: '%s': We are not launching another program pal\n");
	return (127);
}
