/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:19:24 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/07 05:13:08 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_widthh;
int g_preci;
int g_flag;
int g_count;
int g_indice;
int g_point;

void		pourcent_dixu(va_list arg, char *str, int preci1, int i)
{
	char	*s;

	s = NULL;
	if (str[i] == 'd' || str[i] == 'i')
		s = ft_itoa(va_arg(arg, int));
	else if (str[i] == 'u')
		s = ft_utoa(va_arg(arg, unsigned int));
	else if (str[i] == 'x')
		s = ft_hexa(va_arg(arg, unsigned int));
	else if (str[i] == 'X')
		s = ft_hexa_upper(va_arg(arg, unsigned int));
	else if (str[i] == 's')
	{
		s = va_arg(arg, char *);
		s = (s ? s : ft_strdup("(null)"));
	}
	else if (str[i] == 'p')
	{
		s = ft_strjoin("0x", (ft_hexa_p(va_arg(arg, unsigned long long))));
		if (s[2] == '0' && g_point == 1)
			s[2] = '\0';
	}
	g_count = ft_strlen(s);
	s = ft_print_str(s, preci1, str, i);
	ft_putstr(s, &g_indice);
}

int			pourcent_pourcent(char *str, int preci1, int i)
{
	while (str[i] == '%' && str[i - 1] == '%')
	{
		ft_putchar('%', &g_indice);
		i += (i + 2 < ft_strlen(str)) ? 2 : 1;
	}
	if (str[i] == '%')
		ft_putstr(ft_print_str(ft_strdup("%"), preci1, str, i++), &g_indice);
	if (str[i] != 's' && str[i] != 'x' && str[i] != 'X' && str[i] != 'u'
			&& str[i] != 'p' && str[i] != 'i' &&
				str[i] != 'd' && str[i] != 'c' && str[i] != '%')
	{
		if (str[i - 1] == '%' && ((str[i] <= 'z' && str[i] >= 'a')
			|| (str[i] <= 'Z' && str[i] >= 'A') ||
				str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			ft_putchar(str[i], &g_indice);
		i = place(str, i);
	}
	return (i);
}

int			checkout_i(char *str, int i)
{
	if (str[i] == '%' && str[i + 1] == '%')
		i++;
	if (str[i] != '\0' && str[i] != '%')
		i++;
	while ((str[i] != '\0' && str[i] != '%'))
	{
		ft_putchar(str[i], &g_indice);
		i++;
	}
	return (i);
}

int			checkout_char(char *str, int i)
{
	while (str[i] != '%')
	{
		ft_putchar(str[i], &g_indice);
		i++;
	}
	return (i);
}

void ft_reset(void)
{
	g_widthh = 0;
	g_preci = 0;
	g_flag = 0;
	g_count = 0;
	g_point = 0;
}

int			ft_printf(const char *str1, ...)
{
	int		i;
	int		preci1;
	char	*str;
	va_list	arg;

	va_start(arg, str1);
	str = (char *)str1;
	i = 0;
	g_indice = 0;
	preci1 = 0;
	while (str[i] != '\0')
	{
		i = checkout_char(str, i);
		if (str[i] == '%')
		{
			ft_reset();
			i = ft_indices(&str, &g_flag, arg, i);
			pourcent(arg, str, preci1, i);
			if (str[i] == '%')
				i = pourcent_pourcent(str, preci1, i);
			i = checkout_i(str, i);
			if (str[i] == '\0' || str[i + 1] == '\0')
				return (g_indice);
		}
	}
	va_end(arg);
	return (g_indice);
}
