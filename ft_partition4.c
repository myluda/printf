/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:22:13 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 06:22:14 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_print_spaces_zeroes(char *s, char *str, int i)
{
	int		d;

	d = ft_strlen(s);
	if ((str[i] == '.' || str[i - 1] == '.'))
	{
		s[0] = '\0';
	}
	else
	{
		s[0] = '0';
		s[1] = '\0';
	}
	return (s);
}

int			ft_indices0(char **str, va_list arg, int i)
{
	if ((*str)[i + 1] == '*' && (*str)[i] == '.')
	{
		g_point = 1;
		ft_etoile_preci(str, i, arg);
		i = i + 2;
	}
	else
	{
		g_preci = precision(*str, &i);
		if (g_preci != 0)
			i = i + precision_leng(*str, &i) + 1;
		else if (g_point == 1)
			i++;
	}
	return (i);
}

int			ft_indices(char **str, int *flag, va_list arg, int i)
{
	i++;
	*flag = flags(*str, i);
	if (((*str)[i] == '-') || ((*str)[i] == '0'))
	{
		while (((*str)[i] == '-') || ((*str)[i] == '0'))
			i = i + 1;
	}
	if ((*str)[i] == '*')
	{
		g_widthh = ft_etoile_width(str, i, arg);
		if (g_widthh < 0)
		{
			g_widthh = g_widthh * -1;
			*flag = 1;
		}
		i++;
	}
	else
	{
		g_widthh = width(*str, &i);
		if (g_widthh != 0)
			i = i + leng(g_widthh);
	}
	i = ft_indices0(str, arg, i);
	return (i);
}

char		*ft_print_preci(char *s, int preci1)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * preci1 + g_count + 1);
	k = preci1 + g_count;
	while (k > 0)
	{
		str[i] = s[i];
		i++;
		k--;
	}
	str[i] = '\0';
	return (str);
}

char		*print_preci_s(char *s)
{
	int		i;
	char	*str;
	
	i = 0;
	str = malloc(sizeof(char) * g_preci + 1);
	while (g_preci > 0 && s[i] != '\0')
	{
		str[i] = s[i];
		g_preci--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
