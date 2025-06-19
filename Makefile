#------------VARIABLES-----------#

CC		= cc

RM		= rm -rf

CFLAGS	= -Wall -Werror -Wextra

#--------------------------------#

#----------PIPEX VAR-----------#

NAME	= minishell

SRCS	= src/main.c
SRCS	+= src/envairoment.c src/ft_builtins.c \
		   src/expansion.c src/expansion_next.c \
		   src/built-in/ft_cd.c src/built-in/ft_export.c \
		   src/built-in/ft_echo.c src/built-in/ft_pwd.c \
		   src/built-in/ft_env.c src/built-in/ft_unset.c \
		   src/built-in/ft_exit.c

HEAD	= include/pipex.h

LIB		= libft/libft.a


#--------------------------------#

OBJS = ${SRCS:.c=.o}

all:	
		make -C libft
		make	${NAME}

%.o: %.c ${HEAD} Makefile
			$(CC) ${CFLAGS} -c $< -o $@
#-MMD

${NAME}:	${OBJS}
			make -C libft
			$(CC) ${CFLAGS} $(OBJS) ${LIB} -o $(NAME)

clean:
			make clean -C libft
			@${RM} ${OBJS} ${DEPS}

fclean:		clean
			make fclean -C libft
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re libft
