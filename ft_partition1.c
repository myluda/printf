/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:21:32 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 06:21:43 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_etoile_width(char **str, int i, va_list arg)
{
	int		s;

	s = va_arg(arg, int);
	if ((*str)[i] == '*')
	{
		g_widthh = s;
	}
	return (g_widthh);
}

void		ft_etoile_preci(char **str, int i, va_list arg)
{
	int		s;

	s = va_arg(arg, int);
	if ((*str)[i + 1] == '*')
	{
		if (s < 0)
		{
			s = -2;
		}
		g_preci = s;
	}
}

char		*ft_print_flags_minus0(char *s, int *preci1, int i, int k)
{
	if (g_flag == 2 && ((*preci1 == 0 && g_point == 0)
				|| (*preci1 == -2 && g_point == 1)))
	{
		while (s[k] != '-' && s[k] != '\0')
			k++;
		if (g_point != 1 || g_point == 1)
		{
			while (s[i] == ' ')
				s[i++] = '0';
			i = 0;
			while (s[i] != '0' && s[i] != '\0')
			{
				i++;
				if (s[i] == '-')
					break ;
			}
			if (s[i] == '0' && s[k] == '-')
			{
				s[i] = '-';
				s[k] = '0';
			}
		}
	}
	return (s);
}

char		*ft_print_flag_minus1(char *s, int i, int k)
{
	int		len;
	char	temp;
	int		f;

	if (g_flag == 1)
	{
		while (s[i] == ' ')
			i++;
		len = i;
		while (s[len] != '\0')
			len++;
		f = len - i;
		while (f > 0)
		{
			temp = s[k];
			s[k] = s[i];
			s[i] = temp;
			i++;
			k++;
			f--;
		}
	}
	return (s);
}

char		*ft_print_flags_minus(char *s, int *preci1)
{
	int		k;
	int		i;

	i = 0;
	k = 0;
	if (g_flag == 1)
		return (ft_print_flag_minus1(s, i, k));
	else if (g_flag == 2 && ((*preci1 == 0 && g_point == 0)
				|| (*preci1 == -2 && g_point == 1)))
		return (ft_print_flags_minus0(s, preci1, i, k));
	return (s);
}
