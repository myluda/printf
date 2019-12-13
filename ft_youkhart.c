/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_youkhart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:22:26 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 06:22:30 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			place(char *str, int i)
{
	int		c;

	c = 0;
	if (str[i] == '*')
		c = 1;
	while (str[i] != '%')
	{
		i--;
		if (str[i] == '%')
		{
			return (i);
		}
	}
	return (i);
}

char		*ft_pourcent_print(char *s, int preci1, char *str, int i)
{
	int		c;
	int		d;

	d = 0;
	c = 0;
	if ((g_preci == -2 && g_flag != 2) || (str[i] == '%' && g_flag == 0)
			|| (str[i] == 'c' && s[0] == '\0')
				|| ((g_point == 0 && g_widthh && preci1 == 0) && str[i] == 's'))
		s = ft_print_spaces(s, &preci1, i, str);
	else if (str[i] == '%' && g_flag == 1)
	{
		s = ft_print_spaces(s, &preci1, i, str);
		d = ft_strlen(s);
		s[d - 1] = ' ';
		s[0] = '%';
	}
	else if (str[i] == '%' && g_flag == 2)
	{
		s = ft_print_spaces(s, &preci1, i, str);
		while (s[c] == ' ')
			s[c++] = '0';
	}
	return (s);
}

char		*ft_pourcent_print1(char *s, int preci1, char *str, int i)
{
	if (str[i] == 'c' && s[0] == '\0' && !g_widthh)
	{
		g_indice = 1;
		s = ft_print_spaces(s, &preci1, i, str);
		return (s);
	}
	else if ((g_preci <= g_widthh && str[i] == 's' && g_point == 1)
		|| ((g_preci > g_widthh) && str[i] == 's' && s[0] != '\0'))
	{
		s = print_preci_s(s);
		s = ft_print_spaces(s, &preci1, i, str);
		return (s);
	}
	else if (s[0] == '\0' && str[i] == 's' && g_widthh == 0)
		return (ft_strdup(""));
	return (0);
}

char		*ft_pourcent_print2(char *s, int preci1, char *str, int i)
{
	int d;
	int c;

	c = 0;
	d = 0;
	if ((s[0] == '0' && s[1] == '\0')
		&& g_point == 1 && g_preci == 0 && g_flag == 1)
	{
		d = g_widthh;
		s = ft_print_spaces(s, &preci1, i, str);
		c = precision_leng(str, &i);
		if ((c != 0 || g_widthh) && s[0] != '0')
			s[ft_strlen(s) - 1] = ' ';
		else if (d == 1 && c == 0)
		{
			s[0] = ' ';
			s[1] = '\0';
		}
		else
			s[0] = ' ';
		return (s);
	}
	return (s);
}

char		*ft_pourcent_print3(char *s, int preci1, char *str, int i)
{
	int		d;
	int		c;

	c = 0;
	d = 0;
	if ((s[0] == '0' && s[1] == '\0') && g_point == 1 && g_preci == 0)
	{
		d = g_widthh;
		s = ft_print_spaces(s, &preci1, i, str);
		c = precision_leng(str, &i);
		if ((c != 0 || g_widthh) && s[0] != '0')
			s[ft_strlen(s) - 1] = ' ';
		else if (d == 1 && c == 0)
		{
			s[0] = ' ';
			s[1] = '\0';
		}
		else
			s[0] = '\0';
		return (s);
	}
	return (0);
}
