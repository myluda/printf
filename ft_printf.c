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
/*int     width_leng(char *str, int i)
{
    int width;
    if(str[i + 1] >= '0' && str[i + 1] <= '9')
    {
        width = ft_atoi(&str[i + 1]);
       // return (width);
    }
    return (leng(width));
}*/

int     width(char *str, int i)
{
    int width;
    if(str[i] >= '0' && str[i] <= '9')
    {
        width = ft_atoi(&str[i]);
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
char	*ft_strrev_minus(char *str)
{
	int		i;
	int		k;
	int		j;
	char	temp;

	i = 0;
	while (str[i] != '-' && str[i] != '\0')
	{
		i++;
	}
    if(str[i] == '\0')
    {
        return (str);
    }
    temp = str[i];
    str[i] = str[0];
    str[0] = temp;
	return (str);
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
    return str;
}
char    *ft_print_spaces(char *s,int widthh,int preci)
{
    char *str;
    int  c;
    int d;

    d = ft_strlen(s);
    c = widthh - preci;
    str = malloc(sizeof(char) * widthh + 1);
    while(d >= 0)
    {
        str[widthh] = s[d];
        d--;
        widthh--;
    }
    while(widthh >= 0)
    {
        str[widthh--] = ' ';
    }
    str[widthh] = ' ';
    str = ft_strrev_minus(str);
    return str;
}
char    *ft_print_spaces_zeroes(char *s,int widthh,int preci)
{
    char *str;
    int  c;
    int d;
    int i;

    i = 0;
    d = ft_strlen(s);
    c = widthh - preci;
    str = malloc(sizeof(char));
    if (s[0] == '0' && s[1] == '\0')
    {
        s[0] = '\0';
    }
    str[0] = '\0';
    return str;
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
    int widthh;
    va_list arg;
    va_start(arg, str1);
    str = (char *)str1;

    i = 0;
    
    while(str[i] != '\0')
    {
        if(str[i] == '%')
        {
                flag = flags(str,i);
                if (flag == 0)
                {
                    i++;
                }
                widthh = width(str,i);
                if (widthh != 0)
                {
                    i = i + leng(widthh);
                } 
                
                preci = precision(str,i);
                if (preci != 0)
                {
                    i = i + precision_leng(str,i);
                }
                if(str[i + 1] == 'c')
                {
                    ft_putchar(va_arg(arg,int));
                }
                if (widthh && !preci)
                    i = i - 1;
                if(str[i + 1] == 'd' || str[i + 1] == 'i')
                {
                    s = ft_itoa(va_arg(arg, int));
                    count = ft_strlen(s);
                   /* if (s[0] == '0' && s[1] == '\0')
                    {
                        return (0);
                    }*/
                    
                    if ((s[0] == '0' && s[1] == '\0') && preci == 0 && widthh == 0)
                    {
                      s = ft_print_spaces_zeroes(s,count,preci);
                      printf("%s",s);
                      return 0;
                    } 
                    else if (count >= preci && count > widthh)
                    {
                        ft_putstr(s);
                    }
                    else if ((preci > count) && (preci > widthh))
                    {
                        printf("%s",ft_print_zero(s,count,preci));
                    }
                    else if ((widthh > count) && (widthh > preci))
                    {
                        if (count > preci)
                        {
                            preci = count;
                        } 
                        s = ft_print_zero(s,count,preci);
                        printf("%s",ft_print_spaces(s,widthh,preci));
                    } 
                    else if(count >= widthh)
                    {
                        printf("%s",s);
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
    int a = 59999;
    printf("%3.9d\n", a);
    ft_printf("%3.9d\n", a);
}
