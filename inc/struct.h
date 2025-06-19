#ifndef STRUCT_H
# define STRUCT_H

# define SHELL "Minichell"

typedef struct s_env	t_env;

struct s_env
{
	char	*key; //var_name
	char	*value; //value_var
	t_env	*next;
};

typedef struct s_token	t_token;

struct s_token //s_token t_token
{
	int 	index; //added
	char	*word;//data
	int		type;
	t_token	*next;
};

typedef enum e_token_type
{
	T_GENERAL,
	T_CMD,       // COMANDO O ARGUMENTO
	T_PIPE,      // | PIPE
	T_REDIR_IN,  // < IN
	T_REDIR_OUT, // > OUT
	T_HEREDOC,   // << HEREDOC
	T_APPEND,    // >> APPEND
	T_INFILE,    // INFILE
	T_OUTFILE,   // OUTFILE
	T_LIMITER,   // (str) DELIMITER HEREDOC
	T_OPEN,      // (
	T_CLOSE,     // )
	T_ERROR,     // ERROR
    T_SIZE
}t_token_type;

typedef struct s_file	t_file;

struct s_file //s_parser t_parser
{
	char	*file_name; //cmd
	int		type; //open or close redir_in/redir_out
	t_file	*next;
};


typedef struct s_cmd	t_cmd;

struct s_cmd //s_shell t_shell
{
	char	**argv;
	char	*path;
	t_file	*files;
	t_cmd	*next;
};

typedef struct s_shell
{
	char	**envp;     //Ah que quitarlo
	char **paths;       // variables de entorno del sistema
	char **cmd_args;    // comando seguido de argumentos
	int count_cmd_args; // cantidad de comando + argumentos
	t_env	*env;
	t_token *token;
	t_file	*file;
	int		status;
	int		finished;
}	t_shell;

void	delete_env(t_env *env);
void	print_env(t_env *env);

#endif
