#include "../inc/libft.h"
#include "../inc/builtins.h"

int	(*is_built(char *str))(char **, t_shell *)
{
	if (!ft_strncmp(str, "cd", 3))
		return (ft_cd);
	if (!ft_strncmp(str, "echo", 5))
		return (ft_echo);
	if (!ft_strncmp(str, "env", 4))
		return (ft_env);
	if (!ft_strncmp(str, "exit", 5))
		return (ft_exit);
	if (!ft_strncmp(str, "export", 7))
		return (ft_export);
	if (!ft_strncmp(str, "pwd", 4))
		return (ft_pwd);
	if (!ft_strncmp(str, "unset", 6))
		return (ft_unset);
	return (NULL);
}
