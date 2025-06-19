#ifndef STRUCT_H
# define STRUCT_H

# define SHELL "Minichell"

typedef struct s_env	t_env;

struct s_env
{
	t_env	*next;
	char	*key;
	char	*value;
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
	t_token	*next;
	char	*word;
	int		type;
};

typedef struct s_file	t_file;

struct s_file
{
	t_file	*next;
	char	*file_name;
	int		type;
};

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	t_cmd	*next;
	char	*path;
	char	**argv;
	t_file	*files;
};

void	delete_env(void *env);
void	print_env(void *env);

#endif
