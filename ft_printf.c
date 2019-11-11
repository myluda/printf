/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:19:24 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/11/11 12:25:56 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
    int i;
    va_list arg;
    va_start(arg, str);

    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '%')
        {
            if(str[i + 1] == 'c')
            {
                ft_putchar(va_arg(arg,int));
            }
            if(str[i + 1] == 'd')
            {
                ft_putstr((ft_itoa(va_arg(arg, int))));
            }
            if(str[i + 1] ==)
        }
        
        i++;
    }
    return 0;
}
int main()
{
ft_printf("%d",-120);
}
