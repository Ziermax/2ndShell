#ifndef STRUCT_H
# define STRUCT_H

# define SHELL "Minichell"

typedef struct s_env	t_env;

struct s_env
{
	char	*key;
	char	*value;
	t_env	*next;
}

void	delete_env(t_env *env);
void	print_env(t_env *env);

#endif
