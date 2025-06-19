/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  libft.h                                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gergarci <gergarci@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:19:21 by gergarci          #+#    #+#             */
/*  Updated: 2025/06/19 03:40:37 by mvelazqu           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define START 0
# define END 2147483647

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Part 1
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
//int		ft_isascii(int c); Is is necesary?
int		ft_isspace(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len); //mirar tuto slag
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

//Part 2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//Bonus
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//Extras
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
void	ft_write_pstr(char *c, int len, int *ch_print);
void	ft_print_char(char c, int *ch_print);
void	ft_print_string(char *str, int *ch_print);
int		ft_print_num(long num_in, int *ch_print, int is_uni);
int		ft_print_hex(unsigned int num_in, int *ch_print, int is_low);
int		ft_print_ptr(unsigned long num_in, int *ch_print);

//Extras Maxi
int		fd_printf(int fd, const char *str, ...);
	//joins
char	*ft_threejoin(char *str1, char *str2, char *str3);
char	*ft_splitjoin(char	**split);
char	*ft_multiplejoin(int num, ...);
	//List needs that 'next' var is the first element of struct
void	lst_add_back(void *list, void *node);
void	lst_add_front(void *list, void *node);
void	lst_clear(void *list, void (*del)(void *));
void	lst_for_each(void *list, void (*func)(void *));
	//array
int		ft_split_charlen(char **split);
int		ft_arraylen(void *array);
void	*add_dir(void *array, void *dir);
void	*add_array(void *array, void *to_add);
void	free_array(void **array);
char	**ultra_split(char *str, char *(*skip)(char *), char *(*next)(char *));
char	*no_skip(char *str);
char	*skip_space(char *str);

#endif
