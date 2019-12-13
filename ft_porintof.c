/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_porintof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:42:05 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 06:42:07 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_pourcent_print4(char *s, int preci1, char *str, int i)
{
	if (((s[0] == '0' && s[1] == '\0') ||
		(s[0] == '\0')) && g_preci == 0 && g_widthh == 0)
	{
		s = ft_print_spaces_zeroes(s, str, i);
		return (s);
	}
	else if (str[i] == 's')
	{
		preci1 = g_preci;
		s = ft_print_preci(s, preci1);
		s = ft_print_spaces(s, &preci1, i, str);
		return (s);
	}
	return (s);
}

char		*ft_pourcent_print5(char *s, int preci1, char *str, int i)
{
	if ((g_widthh > g_count) && (g_widthh > g_preci))
	{
		preci1 = g_preci;
		if (g_count > g_preci)
			g_preci = g_count;
		s = ft_print_zero(s, g_count);
		s = ft_print_spaces(s, &preci1, i, str);
	}
	else if ((g_preci >= g_count) && (g_preci >= g_widthh))
	{
		preci1 = g_preci;
		s = ft_print_zero(s, g_count);
		s = ft_strrev_minus(s, &preci1);
	}
	else if (g_point == 1
		&& (s[0] == '0' && s[1] == '\0') && (g_widthh == 0 || g_widthh == 1))
		s = ft_only_zero(s);
	else if (g_count >= g_preci && g_count > g_widthh)
		return (s);
	else if (g_count >= g_widthh)
		return (s);
	return (s);
}

char		ft_print_str1(char *s, int preci1, char *str, int i)
{
	if (((g_preci == -2 && g_flag != 2) || (str[i] == '%' && g_flag == 0)
		|| (str[i] == 'c' && s[0] == '\0') || ((g_point == 0 && g_widthh
			&& preci1 == 0) && str[i] == 's')) || (str[i] == '%' &&
				g_flag == 1) || (str[i] == '%' && g_flag == 2))
		return (1);
	else if ((str[i] == 'c' && s[0] == '\0' && !g_widthh) ||
		((g_preci <= g_widthh && str[i] == 's' && g_point == 1)
			|| ((g_preci > g_widthh) && str[i] == 's' && s[0] != '\0'))
				|| (s[0] == '\0' && str[i] == 's' && g_widthh == 0))
		return (2);
	return (0);
}

char		*ft_print_str(char *s, int preci1, char *str, int i)
{
	int		c;

	c = 0;
	if (ft_print_str1(s, preci1, str, i) == 1)
		return (ft_pourcent_print(s, preci1, str, i));
	else if (ft_print_str1(s, preci1, str, i) == 2)
		return (ft_pourcent_print1(s, preci1, str, i));
	else if ((s[0] == '0' && s[1] == '\0')
		&& g_point == 1 && g_preci == 0 && g_flag == 1)
		return (ft_pourcent_print2(s, preci1, str, i));
	else if ((s[0] == '0' && s[1] == '\0') && g_point == 1 && g_preci == 0)
		return (ft_pourcent_print3(s, preci1, str, i));
	else if ((((s[0] == '0' && s[1] == '\0') || (s[0] == '\0'))
		&& g_preci == 0 && g_widthh == 0) || (str[i] == 's'))
		return (ft_pourcent_print4(s, preci1, str, i));
	else if (((g_widthh > g_count) && (g_widthh > g_preci)) ||
		((g_preci >= g_count) && (g_preci >= g_widthh))
			|| (g_point == 1 && (s[0] == '0' && s[1] == '\0')
				&& (g_widthh == 0 || g_widthh == 1))
					|| (g_count >= g_preci && g_count > g_widthh)
						|| (g_count >= g_widthh))
		return (ft_pourcent_print5(s, preci1, str, i));
	return (0);
}

void		pourcent_c(va_list arg, char *str, int preci1, int i)
{
	char	*s;
	char	*str1;

	s = malloc(sizeof(char) * 2);
	s[0] = (char)va_arg(arg, int);
	s[1] = 0;
	str1 = ft_strcpyy(str1, s);
	s = ft_print_str(s, preci1, str, i);
	if ((g_point == 1 || g_point == 0) && str1[0] == '\0' && g_flag != 1)
		ft_putstr_c(s, &g_indice);
	else if (g_flag == 1 && str1[0] == '\0')
		ft_putstr_r(s, &g_indice);
	else if (s[0] == '\0')
		ft_putstr_c(s, &g_indice);
	else
		ft_putstr(s, &g_indice);
}
