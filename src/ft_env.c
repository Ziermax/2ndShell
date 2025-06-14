#include "../inc/envairoment.h" 
#include "../inc/libft.h"

void	print_env(t_env	*env)
{
	while (env)
	{
		ft_printf(1, "%s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
}

int	ft_env(char **argc, t_env **env)
{
	if (!argc || !env)
		return (2);
	if (!argc[1])
		return (print_env(*env), 0);
	if (argc[1][0] == '-')
		return (ft_printf(2, SHELL ": env is not accepting option today\n"), 125);
	ft_printf(2, "env: '%s': No such file nor directory\n");
	return (127);
}
