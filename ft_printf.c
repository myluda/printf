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

int     leng(int c)
{
    int count;

    count = 0;
    while(c != 0)
    {
        c = c / 10;
        count++;
    }
    return (count);
}

int     flags(char *str,int i)
{
    if (str[i + 1] == '0' || str[i + 1] == '-')
    {
        if (str[i + 1] == '-')
            return (1);
        return (2);
    }
    return (0);
}
int     width_leng(char *str, int i)
{
    int width;
    if(str[i + 1] >= '0' && str[i + 1] <= '9')
    {
        width = ft_atoi(&str[i + 1]);
       // return (width);
    }
    return (leng(width));
}

int     width(char *str, int i)
{
    int width;
    if(str[i] >= '0' && str[i] <= '9')
    {
        width = ft_atoi(&str[i + 1]);
        return (width);
    }
    return (0);
}
int     precision_leng(char *str,int i)
{
    int precision;
    if(str[i] == '.')
    {
        precision = ft_atoi(&str[i + 1]);
        return leng(precision);
    }
    return(0);
}
int     precision(char *str,int i)
{
    int precision;
    if(str[i] == '.')
    {
        precision = ft_atoi(&str[i + 1]);
        return(precision);
    }
    return(0);
}

char    *ft_print_zero(char *s,int count,int precision)
{
    char    *str;
    str = malloc(sizeof(char) * precision + 1);
    while(count >= 0)
    {
        str[precision--] = s[count--];
    }
    while(precision >= 0)
    {
        str[precision--] = '0';
    }
    printf("%s",str);
}
int ft_printf(const char *str1, ...)
{
    int i;
    int f;
    char *str;
    int flag;
    int count;
    char *s;
    int preci;
    int r;
    va_list arg;
    va_start(arg, str1);
    str = (char *)str1;

    i = 0;
    
    while(str[i] != '\0')
    {
        if(str[i] == '%')
        {
                r = flags(str,i);
                if (r == 0)
                {
                    i++;
                }
                r = width(str,i);
                if (r != 0)
                {
                    i = i + width_leng(str,i);
                }
                r = precision(str,i);
                if (r != 0)
                {
                    i = i + precision_leng(str,i);
                }
                if(str[i + 1] == 'c')
                {
                    ft_putchar(va_arg(arg,int));
                }
                if(str[i + 1] == 'd' || str[i + 1] == 'i')
                {
                    s = ft_itoa(va_arg(arg, int));
                    count = ft_strlen(s);
                    if (count > r)
                    {
                        ft_putstr(s);
                    }
                    else{
                    //preci = precision(str,i);
                    ft_print_zero(s,count,r);
                    }
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
                if(str[i] == 'x')
                {
                    ft_putstr(ft_hexa(va_arg(arg,unsigned int)));
                }
                if(str[i] == 'X')
                {
                    ft_putstr(ft_hexa_upper(va_arg(arg,unsigned int)));
                }
                i++;
        }
        i++;
    }
    return 0;
}
int main()
{
    unsigned int a = 484817151;
    printf("%.50d\n",a);
   ft_printf("%.50d\n",a);
}
