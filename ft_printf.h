/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:17:24 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 13:17:26 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int				g_widthh;
int				g_preci;
int				g_flag;
int				g_count;
int				g_indice;
int				g_point;

int				ft_printf(const char *str1, ...);
char			*ft_utoa(unsigned int n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strlen(char *str);
char			*ft_hexa(unsigned long long c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
void			ft_putstr(char *str, int *indice);
void			ft_putchar(char c, int *indice);
char			*ft_hexa_upper(unsigned long long c);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *src);
int				ft_isalpha(int str);
void			ft_putstr_c(char *str, int *indice);
char			*ft_hexa_p(unsigned long long c);
char			*ft_strcpyy(const char *s1, char *s2);
void			ft_putstr_r(char *str, int *indice);
int				ft_etoile_width(char **str, int i, va_list arg);
void			ft_etoile_preci(char **str, int i, va_list arg);
char			*ft_print_flags_minus0(char *s, int *preci1, int i, int k);
char			*ft_print_flag_minus1(char *s, int i, int k);
char			*ft_print_flags_minus(char *s, int *preci1);
int				leng(int c);
int				flags(char *str, int i);
int				width(char *str, int *i);
int				precision_leng(char *str, int *i);
int				precision(char *str, int *i);
int				ft_strrev_minus1(char *str);
char			*ft_strrev_minus(char *str, int *preci1);
char			*ft_print_zero(char *s, int count);
char			*ft_print_spaces(char *s, int *preci1, int i, char *str1);
char			*ft_only_zero(char *s);
char			*ft_print_spaces_zeroes(char *s, char *str, int i);
int				ft_indices0(char **str, va_list arg, int i);
int				ft_indices(char **str, int *flag, va_list arg, int i);
char			*ft_print_preci(char *s, int preci1);
char			*print_preci_s(char *s);
char			*ft_pourcent_print4(char *s, int preci1, char *str, int i);
char			*ft_pourcent_print5(char *s, int preci1, char *str, int i);
char			ft_print_str1(char *s, int preci1, char *str, int i);
char			*ft_print_str(char *s, int preci1, char *str, int i);
void			pourcent_c(va_list arg, char *str, int preci1, int i);
int				place(char *str, int i);
char			*ft_pourcent_print(char *s, int preci1, char *str, int i);
char			*ft_pourcent_print1(char *s, int preci1, char *str, int i);
char			*ft_pourcent_print2(char *s, int preci1, char *str, int i);
char			*ft_pourcent_print3(char *s, int preci1, char *str, int i);
void			pourcent_dixu(va_list arg, char *str, int preci1, int i);
void			pourcent(va_list arg, char *str, int preci1, int i);
char			*ft_strchr(char *str, int c);
#endif
