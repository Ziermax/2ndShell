#ifndef STRUCT_H
# define STRUCT_H

# define SHELL "Minichell"

typedef struct s_env	t_env;

struct s_env
{
	char	*key;
	char	*value;
	t_env	*next;
};

typedef struct s_shell
{
	char	**envp;//Ah que quitarlo
	t_env	*env;
	int		status;
	int		finished;
}	t_shell;

typedef struct s_token	t_token;

struct s_token
{
	char	*word;
	int		type;
	t_token	*next;
};

typedef struct s_file	t_file;

struct s_file
{
	char	*file_name;
	int		type;
	t_file	*next;
};

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char	*path;
	char	**argv;
	t_file	*files;
	t_cmd	*next;
};

void	delete_env(t_env *env);
void	print_env(t_env *env);

#endif
