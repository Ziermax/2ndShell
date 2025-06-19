#ifndef EXPANSION_H
# define EXPANSION_H

int		is_varstart(char c);
char	*next_word(char *str);
char	*next_var(char *str);
char	*next_quote(char *str);

#endif
