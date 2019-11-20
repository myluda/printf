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

int widthh;
int preci;
int flag;
int count;

int         ft_etoile_width(char **str,int i,va_list arg)
{
    int s;
    s = va_arg(arg, int);
    if((*str)[i] == '*')
    {
        widthh = s;
    }
    return widthh;
}
void         ft_etoile_preci(char **str,int i,va_list arg)
{
    int s;
    s = va_arg(arg, int);
    if((*str)[i + 1] == '*')
    {
        preci = s;
    }
}

char    *ft_print_flags_minus(char *s,int *preci1)
{
    int f;
    int len;
    int k;
    char temp;
    int i;

    i = 0;
    k = 0;
    if (flag == 1)
    {
        while(s[i] == ' ')
        {
            i++;
        }
        len = i;
        while(s[len] != ' ' && s[len] != '\0')
        {
            len++;
        }
        f = len - i;
        while(f > 0)
        {
            temp = s[k];
            s[k] = s[i];
            s[i] = temp;
            i++;
            k++;
            f--;
        }
        return s;
    }
    else if (flag == 2 && *preci1 == 0)
    {
        while(s[k] != '-' && s[k] != '\0')
            k++;

        while(s[i] == ' ')
            s[i++] = '0';
        if(s[k] == '-')
        {
            s[0] = '-';
            s[i] = '0';
        }     
        return s;
    }
}

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

int     width(char *str, int *i)
{
    int width;
    while(str[*i] == '-' || str[*i] == '0')
    {
        *i = *i + 1;
    }
    if(str[*i] >= '0' && str[*i] <= '9')
    {
        width = ft_atoi(&str[*i]);
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
char	*ft_strrev_minus(char *str,int *preci1)
{
	int		i;
	int		k;
	int     j;
	char	temp;

    k = 0;
	i = 0;
	while (str[i] != '-' && str[i] != '\0')
	{
		i++;
	}
    j = i;
    while(str[j] != '\0')
        j++;
    j = j - i;
    while(str[k] == ' ')
    {
        k++;
    }
    if(str[i] == '\0')
    {
        return (str);
    }
    if (str[i] == '-' && (*preci1 >= j))
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
char    *ft_print_zero(char *s,int count)
{
    char    *str;
    str = malloc(sizeof(char) * preci + 1);
    while(count >= 0)
    {
        str[preci--] = s[count--];
    }
    while(preci >= 0)
    {
        str[preci--] = '0';
    }
    return str;
}
char    *ft_print_spaces(char *s,int *preci1,int i,char *str1)
{
    char *str;
    //int  c;
    int d;
    int c;
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
     if(str[remaind - 1] == '0' && (str[remaind - 2] < '0' || str[remaind - 2] > '9') && *preci1 == 0 && str1[i] == '.')
        str[remaind - 1] = ' '; 
    str = ft_strrev_minus(str, preci1);
    str = ft_print_flags_minus(str,preci1);
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
char    *ft_print_spaces_zeroes(char *s,char *str,int i)
{
    int  c;
    int d;

    d = ft_strlen(s);
    if (str[i] == '.')
    {
        s[0] = '\0';
    }
    else
    {
        s[0] = '0';
        s[1] = '\0';
    }
    return s;
}
int     ft_indices(char **str,int *flag,va_list arg)
{
    int i;

    i = 0;
    *flag = flags(*str,i);
    if(((*str)[i + 1] == '-') || ((*str)[i + 1] == '0'))
    {
    while(((*str)[i + 1] == '-') || ((*str)[i + 1] == '0'))
    {
        i = i  + 1;
    }
    i = i - 1;
    }
    if (*flag == 0 && (*str)[i + 1] != 'd')
    {
        i++;
    }
    else 
        i = i + 2;
    if ((*str)[i] == '*')
    {
        widthh = ft_etoile_width(str,i,arg);
        if(widthh < 0)
        {
            widthh = widthh * -1;
            *flag = 1;
        }
        i++;
    }
    else
    {
        widthh = width(*str, &i);
        if (widthh != 0)
        {
        i = i + leng(widthh);
        }
    }
    if((*str)[i + 1] == '*')
    {
        ft_etoile_preci(str,i,arg);
        i = i + 1;
    }
    else
    {
        preci = precision(*str,&i);
        if (preci != 0)
        {
            i = i + precision_leng(*str,&i);
        }
    }
    if ((*str)[i] == 'd')
        i = i - 1;
    return(i);
}

char        *ft_print_str(char *s,int preci1,char *str,int i)
{
     if ((s[0] == '0' && s[1] == '\0') && preci == 0 && widthh == 0)
    {
        s = ft_print_spaces_zeroes(s,str,i);
        return (s);
    }
    else if (str[i] == '.' && (s[0] == '0' && s[1] == '\0') && (widthh == 0 || widthh == 1))
    {
        s = ft_only_zero(s);
        return s;
    }
    else if ((widthh > count) && (widthh > preci))
    {
        preci1 = preci;
        if (count > preci)
        {
        preci = count;
        } 
        s = ft_print_zero(s,count);
        s = ft_print_spaces(s,&preci1,i,str);
        return s;
    } 
    else if ((preci >= count) && (preci >= widthh))
    {
        preci1 = preci;
        s = ft_print_zero(s,count);
        s = ft_strrev_minus(s, &preci1);
        return s;
    }
    else if (count >= preci && count > widthh)
    {
        return s;
    }
    else if(count >= widthh)
    {
        return s;
    }
} 

int         ft_printf(const char *str1, ...)
{
    int i;
    // int f;
    char *str;
    char *s;
    // int r;
    int preci1;
    va_list arg;
    va_start(arg, str1);
    str = (char *)str1;
    i = 0;

    while(str[i] != '\0')
    {
        /*while(str[i] != '%')
        {
            ft_putchar(str[i]);
            i++;
        } */
        if(str[i] == '%')
        {
            i = ft_indices(&str,&flag,arg); 
                if(str[i + 1] == 'c')
                {
                    ft_putchar(va_arg(arg,int));
                }
                if(str[i + 1] == 'd' || str[i + 1] == 'i')
                {
                    s = ft_itoa(va_arg(arg, int));
                    count = ft_strlen(s);
                    ft_putstr(ft_print_str(s,preci1,str,i));
                }
                if(str[i + 1] == 'p')
                {
                    s = ft_strjoin("0x",(ft_hexa(va_arg(arg,unsigned long long))));
                    count = ft_strlen(s);
                    ft_putstr(ft_print_str(s,preci1,str,i));
                }
                if(str[i + 1] == 's')
                {
                    ft_putstr(va_arg(arg,char *));
                }
                if(str[i + 1] == 'u')
                {
                    s = ft_utoa(va_arg(arg,unsigned int));
                    count = ft_strlen(s);
                    ft_putstr(ft_print_str(s,preci1,str,i));
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
    int a = 5;
    printf("%6.40p\n",&a);
    ft_printf("%6.40p",&a);
    // printf("b");
    // printf("\n");
    //printf("\n");
}
