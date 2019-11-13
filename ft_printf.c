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
            if(str[i + 1] == 'd' || str[i + 1] == 'i')
            {
                ft_putstr((ft_itoa(va_arg(arg, int))));
            }
            if(str[i + 1] == 'p')
            {
                ft_putstr(ft_strjoin("0x",(ft_hexa(va_arg(arg,unsigned long long)))));
            }
            if(str[i + 1] == 's')
            {
                ft_putstr(va_arg(arg,char *));
            }
            if(str[i + 1] == 'u')
            {
                ft_putstr(ft_utoa(va_arg(arg,unsigned int)));
            }
            if(str[i + 1] == 'x')
            {
                ft_putstr(ft_hexa(va_arg(arg,unsigned int)));
            }
            if(str[i + 1] == 'X')
            {
                ft_putstr(ft_hexa_upper(va_arg(arg,unsigned int)));
            }
        }
        
        i++;
    }
    return 0;
}
int main()
{
    unsigned int a = 484817151;
    printf("%4.3d\n",6);
    ft_printf("%4.3d\n",6);
}
