/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 08:00:12 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/08 08:00:17 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pourcent(va_list arg, char *str, int preci1, int i)
{
	if (str[i] == 'c')
		pourcent_c(arg, str, preci1, i);
	else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u'
			|| str[i] == 'x' || str[i] == 'X' || str[i] == 's' || str[i] == 'p')
		pourcent_dixu(arg, str, preci1, i);
}
