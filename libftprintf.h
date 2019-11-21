#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H


# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char		    *ft_utoa(unsigned int n);
int		        ft_tolower(int c);
int		        ft_toupper(int c);
int		        ft_strlen(char *str);
char            *ft_hexa(unsigned long long c);
char	        *ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
void            ft_putstr(char *str);
void            ft_putchar(char c);
char            *ft_hexa_upper(unsigned long long c);
int				ft_atoi(const char *str);
size_t		    ft_strlcat(char *dst, const char *src, size_t size);
char		    *ft_strdup(const char *src);

#endif
