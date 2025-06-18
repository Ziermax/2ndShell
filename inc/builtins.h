#ifndef BUILTINS_H
# define BUILTINS_H

# include "envairoment.h"

int		(*is_built(char *str))(char **, t_shell *);
int		ft_cd(char **argv, t_shell *shell);
int		ft_echo(char **argv, t_shell *shell);
int		ft_env(char **argv, t_shell *shell);
int		ft_exit(char **argv, t_shell *shell);
int		ft_export(char **argv, t_shell *shell);
int		ft_pwd(char **argv, t_shell *shell);
int		ft_unset(char **argv, t_shell *shell);

#endif
