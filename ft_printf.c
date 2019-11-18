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
int     precision_leng(char *str,int *i)
{
    int precision;
        while(str[*i + 1] == '0')
        {
            *i = *i + 1;
        }
        precision = ft_atoi(&str[*i + 1]);
        return leng(precision);

    return(0);
}
//char    *switch
int     precision(char *str,int *i)
{
    int precision;
    if(str[*i] == '.')
    {
        while(str[*i + 1] == '0')
        {
            *i = *i + 1;
        } 
        if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
            precision = ft_atoi(&str[*i + 1]);
        else
            precision = 0;
        return(precision);
    }
    return(0);
}
char	*ft_strrev_minus(char *str)
{
	int		i;
	int		k;
	// int		j;
	char	temp;
    
    k = 0;
	i = 0;
	while (str[i] != '-' && str[i] != '\0')
	{
		i++;
	}
    while(str[k] == ' ')
    {
        k++;
    }
    if(str[i] == '\0')
    {
        return (str);
    }
    if (str[i] == '-')
    {
    temp = str[i];
    str[i] = str[k - 1];
    str[k - 1] = temp;
    str[i] = '0';
    if(str[0] == '0')
        str = ft_strjoin("-",str);
    }
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
char    *ft_print_spaces(char *s,int widthh,int preci,int *preci1)
{
    char *str;
    int  c;
    int d;
    int remaind;
    remaind = widthh;
    d = ft_strlen(s);
    //c = widthh;
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
     if(str[remaind - 1] == '0' && (str[remaind - 2] < '0' || s[remaind - 2] > '9') && *preci1 == 0)
        str[remaind - 1] = ' '; 
    str = ft_strrev_minus(str);
    return str;
}
char    *ft_only_zero(char *s)
{
    char *str;
    int  c;
    int d;
    int i;

    i = 0;
    d = ft_strlen(s);
    str = malloc(sizeof(char));
    if (s[0] == '0' && s[1] == '\0')
    {
        str[0] = '\0';
    }
    str[1] = '\0';
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
        str[0] = '0';
    }
    str[1] = '\0';
    return str;
}

int ft_printf(const char *str1, ...)
{
    int i;
    // int f;
    char *str;
    int flag;
    int count;
    char *s;
    int preci;
    // int r;
    int widthh;
    int preci1;
    va_list arg;
    va_start(arg, str1);
    str = (char *)str1;

    i = 0;
    
    while(str[i] != '\0')
    {
        if(str[i] == '%')
        {
                flag = flags(str,i);
                if (flag == 0 && str[i + 1] != 'd')
                {
                    i++;
                }
                widthh = width(str,i);
                if (widthh != 0)
                {
                    i = i + leng(widthh);
                } 
                
                preci = precision(str,&i);
                if (preci != 0)
                {
                    i = i + precision_leng(str,&i);
                }
                if(str[i + 1] == 'c')
                {
                    ft_putchar(va_arg(arg,int));
                }
                if (widthh && !preci && str[i] != '.' && str[i] != '0')
                    i = i - 1;
                if(str[i + 1] == 'd' || str[i + 1] == 'i')
                {
                    s = ft_itoa(va_arg(arg, int));
                    count = ft_strlen(s);
                   /* if (s[0] == '0' && s[1] == '\0')
                    {
                        return (0);
                    }*/
                    if (str[i] == '.' && (s[0] == '0' && s[1] == '\0') && widthh == 0)
                    {
                        printf("%s",ft_only_zero(s));
                    }
                    else if ((s[0] == '0' && s[1] == '\0') && preci == 0 && widthh == 0)
                    {
                      s = ft_print_spaces_zeroes(s,count,preci);
                      printf("%s",s);
                    } 
                    else if (count >= preci && count > widthh)
                    {
                        ft_putstr(s);
                    }
                    else if ((preci > count) && (preci >= widthh))
                    {
                        s = ft_print_zero(s,count,preci);
                        s = ft_strrev_minus(s);
                        printf("%s",s);
                    }
                    else if ((widthh > count) && (widthh > preci))
                    {
                        preci1 = preci;
                        if (count > preci)
                        {
                            preci = count;
                        } 
                        s = ft_print_zero(s,count,preci);
                        s = ft_print_spaces(s,widthh,preci,&preci1);
                        printf("%s",s);
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
    int a = -99;
    printf("%.10d\n", a);
    ft_printf("%.10d", a);
    printf("\n");
    //printf("\n");
}
