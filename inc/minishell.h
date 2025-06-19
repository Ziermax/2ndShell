#ifndef MINISHELL_H
# define MINISHELL_H

# include "struct.h"

char	**expand_str(char *str, t_shell *shell);
char	**expand_array(char **array, t_shell *shell);

#endif
