#ifndef ENVAIROMENT_H
# define ENVAIROMENT_H

# include "struct.h"

void	erase_key(char *key, t_env **list);
t_env	*find_key(char *key, t_env *env);
char	*find_value(char *key, t_env *env);
int		copy_value(char *key, char **value_box, t_env *env)
t_env	*change_value(char *key, char *value, t_env *env);
t_env	*add_value(char *key, char *value, t_env **list);
t_env	*expand_value(char *key, char *append, t_env **list);

#endif
