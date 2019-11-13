/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:54:57 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/11/13 17:54:58 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int      calc_leng(unsigned long long c)
{
    int count;

    count = 0;
    while (c != 0)
    {
        c = c / 16;
        count++;
    }
    return (count);
}

static char    *ft_strrev(char *str)
{
    int        i;
    int        k;
    int        j;
    char    temp;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    k = 0;
    j = i - 1;
    while (k < j)
    {
        temp = str[k];
        str[k] = str[j];
        str[j] = temp;
        k++;
        j--;
    }
    return (str);
}

char     *ft_hexa_upper(unsigned long long c)
{
    int cal;
    char *hexa;
    int remainder;
    int i;
    
    i = 0;
    cal = calc_leng(c);
    hexa = malloc(sizeof(char) * cal + 1);
    while (c != 0)
    {
        remainder = c % 16;
        if (remainder < 10)
        {
            hexa[i] = 48 + remainder;
        }
        else
        {
            hexa[i] = 55 + remainder;
        }
        c = c / 16;
        i++;
    }
    hexa[i] = '\0';

    return (ft_strrev(hexa));
}
