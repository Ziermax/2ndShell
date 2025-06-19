#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "../../inc/libft.h"
#include "../../inc/envairoment.h"
/*
cd: cd [-L|[-P [-e]] [-@]] [dir]
    Change the shell working directory.

    Change the current directory to DIR.  The default DIR is the value of the
    HOME shell variable. If DIR is "-", it is converted to $OLDPWD.

    The variable CDPATH defines the search path for the directory containing
    DIR.  Alternative directory names in CDPATH are separated by a colon (:).
    A null directory name is the same as the current directory.  If DIR begins
    with a slash (/), then CDPATH is not used.

    If the directory is not found, and the shell option `cdable_vars' is set,
    the word is assumed to be  a variable name.  If that variable has a value,
    its value is used for DIR.

    Options:
      -L        force symbolic links to be followed: resolve symbolic
                links in DIR after processing instances of `..'
      -P        use the physical directory structure without following
                symbolic links: resolve symbolic links in DIR before
                processing instances of `..'
      -e        if the -P option is supplied, and the current working
                directory cannot be determined successfully, exit with
                a non-zero status
      -@        on systems that support it, present a file with extended
                attributes as a directory containing the file attributes

    The default is to follow symbolic links, as if `-L' were specified.
    `..' is processed by removing the immediately previous pathname component
    back to a slash or the beginning of DIR.

    Exit Status:
    Returns 0 if the directory is changed, and if $PWD is set successfully when
    -P is used; non-zero otherwise.*/

int	change_directory(char *dir, t_env **list)
{
	char	*pwd;
	char	*oldpwd;

	if (copy_value("PWD", &oldpwd, *list) == -1)
		return (fd_printf(2, "cd: setting OLDPWD: %s\n", strerror(errno)), 3);
	if (chdir(dir) == -1)
		return (free(oldpwd),
				fd_printf(2, "cd: %s: %s\n", dir, strerror(errno)), 1);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (free(oldpwd), ft_perro("cd: setting PWD", strerror(errno)), 3);
	if (!change_value("OLDPWD", oldpwd, *list))
		free(oldpwd);
	if (!change_value("PWD", pwd, *list))
		free(pwd);
	return (0);
}

int	ft_cd(char **argv, t_shell *shell)
{
	if (!argv || !*argv)
		return (fd_printf(2, "cd: bad argument\n"), 3);
	++argv;
	if (!ft_strncmp("--help", *argv, 8))
		return (ft_perro("cd: no help provided", NULL), 2);
	if (!argv[0])
		return (ft_perro("cd: argument needed", NULL), 2);
	if (argv[0][0] == '-' && argv[0][1])
		return (fd_printf(2, SHELL ": cd is not accepting options today\n"), 2);
	if (argv[0] && argv[1])
		return (ft_perro(SHELL ": cd: too many arguments", NULL), 1);
	change_directory(argv[0], &shell->env);
	return (0);
}
