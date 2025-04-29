NAME		= libft.a

SRCS		= ft_isx.c ft_itoas+trim.c ft_lst_add+new.c ft_lst_del+map.c \
				ft_lst_iterators.c ft_mainuse.c ft_memm.c ft_putx.c ft_split.c \
				ft_str_cpy+gnrte.c ft_str_finder+comp.c ft_strextras.c get_next_line.c ft_printf.c\
				./printsrc/ft_print_hexnpnt.c ./printsrc/ft_print_num.c ./printsrc/ft_print_strch.c
				 
#SRC_PRINT_DIR 	= ./printsrc/

#SRCS_PRINT = ft_print_hexnpnt.c \
				ft_print_num.c \
				ft_print_strch.c

#P_SRCS	= $(addprefix $(SRC_PRINT_DIR), $(SRCS_PRINT))


HEAD	= ./libft.h

CC		= gcc

AR		 = ar rcs

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

%.o : %.c ${HEAD} Makefile
			${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS} 
			@${AR} ${NAME} ${OBJS}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re 