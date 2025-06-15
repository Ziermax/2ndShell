#include "../inc/libft.h"
#include "../inc/enviroment.h"
/*
unset: unset [-f] [-v] [-n] [name ...]
    Unset values and attributes of shell variables and functions.

    For each NAME, remove the corresponding variable or function.

    Options:
      -f        treat each NAME as a shell function
      -v        treat each NAME as a shell variable
      -n        treat each NAME as a name reference and unset the variable itself
                rather than the variable it references

    Without options, unset first tries to unset a variable, and if that fails,
    tries to unset a function.

    Some variables cannot be unset; also see `readonly'.

    Exit Status:
    Returns success unless an invalid option is given or a NAME is read-only.*/

int	ft_unset(char **argv, t_shell *shell)
{
	int	i;

	if (!argv || !*argv)
		return (ft_printf(2, "unset: bad argument\n"), 3);
	++argv;
	if (!ft_strncmp("--help", *argv, 8))
		return (ft_printf(2, "unset: no help provided\n"), 2); 
	if (argv[0] && argv[0][0] == '-' && argv[0][1])
		return (ft_printf(2, SHELL ": unset is not accepting options today\n"), 2);
	i = 0;
	while (argv[i])
		erase_key(argv[i++], &shell->env);
	return (0);
}
