#include <unistd.h>
#include "../inc/enviroment.h"
/*
pwd: pwd [-LPW]
    Print the name of the current working directory.

    Options:
      -L        print the value of $PWD if it names the current working
                directory
      -P        print the physical directory, without any symbolic links
      -W        print the Win32 value of the physical directory

    By default, `pwd' behaves as if `-L' were specified.

    Exit Status:
    Returns 0 unless an invalid option is given or the current directory
    cannot be read.
*/

int	ft_pwd(char **argv, t_env **env)
{
	char	*cwd;
	
	if (!argv || !*argv)
		return (ft_printf(2, "pwd: bad argument\n"), 3);
	++argv;
	if (!ft_strncmp("--help", *argv, 8))
		return (ft_printf(2, "pwd: no help provided\n"), 2); 
	if (argv[0] && argv[0][0] == '-' && argv[0][1])
		return (ft_printf(2, SHELL ": pwd is not accepting options today\n"), 2);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (ft_printf(2, "pwd: %s\n", strerror(errno)), 1);
	ft_printf(1, "%s\n", cwd);
	free(cwd);
	return (0);
}
