/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:21:52 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 06:21:53 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			leng(int c)
{
	int count;

	count = 0;
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	return (count);
}

int			flags(char *str, int i)
{
	if (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			return (1);
		return (2);
	}
	return (0);
}

int			width(char *str, int *i)
{
	int		width;

	while (str[*i] == '-' || str[*i] == '0')
		*i = *i + 1;
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		width = ft_atoi(&str[*i]);
		return (width);
	}
	return (0);
}

int			precision_leng(char *str, int *i)
{
	int		precision;

	while (str[*i + 1] == '0')
	{
		*i = *i + 1;
	}
	precision = ft_atoi(&str[*i + 1]);
	return (leng(precision));
}

int			precision(char *str, int *i)
{
	int		precision;

	if (str[*i] == '.')
	{
		g_point = 1;
		while (str[*i + 1] == '0')
			*i = *i + 1;
		if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
			precision = ft_atoi(&str[*i + 1]);
		else
			precision = 0;
		return (precision);
	}
	g_point = 0;
	return (0);
}
