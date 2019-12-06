/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:19:24 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/12/04 16:07:20 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int widthh;
int preci;
int flag;
int count;
int indice;
int point;

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
        if(s < 0)
        {
            s = -2;
        }
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
    else if (flag == 2 && *preci1 == 0 && point == 0)
    {
        while(s[k] != '-' && s[k] != '\0')
            k++;
        if(point != 1)
        {
            while(s[i] == ' ')
            s[i++] = '0';
            i = 0;
            while(s[i] != '0' && s[i] != '\0')
            {
            i++;
                if(s[i] == '-')
                {
                    break;
                }
            }
            if(s[i] == '0' && s[k] == '-')
            {
                s[i] = '-';
                s[k] = '0';
            }

        /*if()
        {
            s[0] = '-';
            s[i] = '0';
        }*/
        }     
        return s;
    }
	return s;
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
        point = 1;
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
    point = 0;
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
    //int c;
    int remaind;
    remaind = widthh;
    d = ft_strlen(s);
    //c = widthh;
    str = malloc(sizeof(char) * widthh + 1);
    if (d > widthh)
        widthh = d;
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
    //int  c;
    int d;
    int i;

    i = 0;
    d = ft_strlen(s);
    str = malloc(sizeof(char));
    if (s[0] == '0' && s[1] == '\0')
    {
        str[0] = ' ';
    }
    str[1] = '\0';
    return str;
}
char    *ft_print_spaces_zeroes(char *s,char *str,int i)
{
   // int  c;
    int d;

    d = ft_strlen(s);
    if ((str[i] == '.' || str[i - 1] == '.'))
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
int     ft_indices(char **str,int *flag,va_list arg,int i)
{
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
    if ((*str)[i] == 'd' || (*str)[i] == 's' || (*str)[i] == 'c' || (*str)[i] == 'u' || (*str)[i] == 'x')
        i = i - 1;
    return(i);
}
char        *ft_print_preci(char *s,int preci1)
{
    int i;
    int k;
    i = 0;
    char *str;
    str = malloc(sizeof(char) * preci1 + count + 1);
    k = preci1 + count;
    while(k > 0)
    {
        str[i] = s[i];
        i++;
        k--;
    }
    str[i] = '\0';
    return str;
}
char    *print_preci_s(char *s)
{
    int i;
    char *str;

    i = 0;
    str = malloc(sizeof(char) * preci + 1);
    while(preci > 0)
    {
        str[i] = s[i];
        preci--;
        i++;
    }
    str[i] = '\0';
    return str;
}
int     place(char *str,int i)
{
    int c = 0;
    if (str[i] == '*')
        c = 1;
    while(str[i] != '%')
        {
            i--;
            if(str[i] == '%')
            {
                while(str[i] != 's' && str[i] != 'd' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' && str[i] != 'i' && str[i] != 'p' && str[i] != 'c' && str[i] != '%')
                {
                i++;
                }
                if(str[i] == 's' || str[i] == 'd' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'i'|| str[i] == 'p' || str[i] == 'c')
                {
                    return i;
                }
            }
        }
   while(str[i] == '%' && str[i + 1] != '\0')
    {
        while(str[i + 1] != 's' && str[i + 1] != 'd' && str[i + 1] != 'u' && str[i + 1] != 'x' && str[i + 1] != 'X' && str[i + 1] != 'i' && str[i + 1] != 'p' && str[i + 1] != 'c' && str[i + 1] != '%')
        {
            i++;
        }
        if(str[i + 1] == 's' || str[i + 1] == 'd' || str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == 'i' || str[i+ 1] == 'p' || str[i + 1] == 'c' || str[i + 1] == '%')
        {
            return i + 1;
        }
    }
    return i; 

}
char        *ft_print_str(char *s,int preci1,char *str,int i)
{
    int d;
    int c;

    c = 0;
    if (str[i] == '*' && preci == -2)
    {
        s = ft_print_spaces(s,&preci1,i,str);
        return s;
    }
    else if(str[i + 1] == '%' && flag == 0)
    {
        s = ft_print_spaces(s,&preci1,i,str);
        return s;
    }
    else if(str[i + 1] == '%' && flag == 1)
    {
        s = ft_print_spaces(s,&preci1,i,str);
         d = ft_strlen(s);
         s[d - 1] = ' ';
         s[0] = '%';
         return s;
    }
    else if(str[i + 1] == '%' && flag == 2)
    {
        s = ft_print_spaces(s,&preci1,i,str);
        while(s[c] == ' ')
            s[c++] = '0';
        return s;
    }
    else if(str[i + 1] == 'c' && s[0] == '\0')
    {
        s = ft_print_spaces(s,&preci1,i,str);
        d = ft_strlen(s);
        indice = 1;
       /* s[d] = ' ';
        s[d + 1] = '\0'; */
        return s;  
    }
    else if (str[i + 1] == 'c' && s[0] == '\0' && !widthh)
    {
       // s[0] = '\0';
        indice = 1;
        s = ft_print_spaces(s,&preci1,i,str);
        return s;
    }
   else if (((str[i + 1] != '.' || str[i] == '.') && preci <= widthh) && str[i + 1] == 's' && (str[i - 1] == '.' || str[i] == '.'))
    {
        s = print_preci_s(s);
        s = ft_print_spaces(s,&preci1,i,str);
        return s;
    }
    else if ((str[i + 1] != '.' && preci > widthh) && str[i + 1] == 's' && s[0] != '\0')
    {
        s = print_preci_s(s);
        s = ft_print_spaces(s,&preci1,i,str);
        return s;
    }
    else if ((str[i + 1] != '.' && widthh && preci1 == 0) && str[i + 1] == 's')
    {
        s = ft_print_spaces(s,&preci1,i,str);
        return s;
    } 
    else if(s[0] == '\0' && str[i + 1] == 's')
    {
        return (ft_strdup(""));
    }
    else if((s[0] == '0' && s[1] == '\0') && str[i - 1] == '.' && preci == 0)
    {
        d = widthh;
        s = ft_print_spaces(s,&preci1,i,str);
        c = precision_leng(str,&i);
        if ((c != 0 || widthh) && s[0] != '0')
            s[ft_strlen(s) - 1] = ' ';
        else if (d == 1 && c == 0)
        {
            s[0] = ' ';
            s[1] = '\0';
        }
        else
            s[0] = '\0';
        return s;
    }
   else if (((s[0] == '0' && s[1] == '\0') || (s[0] == '\0')) && preci == 0 && widthh == 0)
    {
        s = ft_print_spaces_zeroes(s,str,i);
        return (s);
    }
    else if (str[i] == '.' && (s[0] == '0' && s[1] == '\0') && (widthh == 0 || widthh == 1))
    {
        s = ft_only_zero(s);
        return s;
    }
    else if (str[i + 1] == 's')
    {
        preci1 = preci; 
            s = ft_print_preci(s,preci1);
        if (widthh > preci1)
            s = ft_print_spaces(s,&preci1,i,str);
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
    return 0;
} 

int         ft_printf(const char *str1, ...)
{
    int i;

    char *str;
    char *s;
    int preci1;
    va_list arg;
    va_start(arg, str1);
    str = (char *)str1;
    i = 0;
    indice = 0;
    preci1 = 0;
    while(str[i] != '\0')
    {
        while(str[i] != '%')
        {
            ft_putchar(str[i],&indice);
            i++;
        }

        if(str[i] == '%')
        {
            i = ft_indices(&str,&flag,arg,i); 
                if(str[i + 1] == 'c')
                {
                    s = malloc(sizeof(char) * 2);
                    s[0] = va_arg(arg,int);
                    //s[1] = '\0';
                    str1 = ft_strcpyy(str1,s);
                    s = ft_print_str(s,preci1,str,i);
                    if(point == 1 && str1[0] == '\0')
                        ft_putstr_c(s,&indice);
                    else
                    {
                        ft_putstr(s,&indice);
                    }
                }
                else if(str[i + 1] == 'd' || str[i + 1] == 'i' || str[i - 1] == 'd' || str[i - 1] == 'i')
                {
                    s = ft_itoa(va_arg(arg, int));
                    count = ft_strlen(s);
                    s = ft_print_str(s,preci1,str,i);
                    ft_putstr(s,&indice);
                }
                else if(str[i + 1] == 'p' || str[i] == 'p')
                {
                    s = ft_strjoin("0x",(ft_hexa_p(va_arg(arg,unsigned long long))));
                    count = ft_strlen(s);
                    if(s[2] == '0' && point == 1)
                        s[2] = '\0';
                    s = ft_print_str(s,preci1,str,i);
                    ft_putstr(s,&indice);
                    i++;
                    //printf("%d",ft_strlen(ft_print_str(s,preci1,str,i)));

                }
               else if(str[i + 1] == 's')
                {
                   s = va_arg(arg,char *);
                   if (s == NULL)
                   {
                      s = ft_strdup("(null)");
                   }
                   count = ft_strlen(s);
                    s = ft_print_str(s,preci1,str,i);
                    ft_putstr(s,&indice);
                    i++;
                }
              else  if(str[i + 1] == 'u')
                {
                    s = ft_utoa(va_arg(arg,unsigned int));
                    count = ft_strlen(s);
                    s = ft_print_str(s,preci1,str,i);
                    ft_putstr(s,&indice);
                    
                }
              else  if(str[i + 1] == 'x' || str[i] == 'x')
                {
                    s = ft_hexa(va_arg(arg,unsigned int));
                    count = ft_strlen(s);
                    s = ft_print_str(s,preci1,str,i);
                    ft_putstr(s,&indice);
                }
              else  if(str[i + 1] == 'X' || str[i] == 'X')
                {
                    s = ft_hexa_upper(va_arg(arg,unsigned int));
                    count = ft_strlen(s);
                    s = ft_print_str(s,preci1,str,i);
                    ft_putstr(s,&indice);
                    i++;
                }
                else  if(str[i + 1] == '%' || str[i] == '%')
                {
                    while((str[i] == '%' && str[i + 1] == '%') || (str[i] == '%' && str[i - 1] == '%'))
                    {
                        ft_putchar('%',&indice);
                        if(i + 2 < ft_strlen(str))
                        {
                            i = i + 2;
                        }
                        else
                        {
                            i++;
                        }
                    }
                        if(str[i + 1] == '%' || str[i] == '%')
                        {
                        s = malloc(sizeof(char) * 2);
                        s[0] = '%';
                        s[1] = '\0';
                        s = ft_print_str(s,preci1,str,i);
                        ft_putstr(s,&indice);
                        }
                }
       /* if (str[i] && str[i + 1] && str[i + 2])
            i = i + 2; */
      // else 
        //    i = i + 2;
        //if(str[i] == '%')
    i = place(str,i) + 1;
    
    while(str[i] != '\0' && str[i] != '%') 
    {
        ft_putchar(str[i],&indice);
        i++;
    }
       /* while(str[i] != '%' && str[i] != '\0' && (str[i + 1] != 'd' && str[i + 1] != 's' && str[i + 1] != 'u' && str[i + 1] != 'x') && str[i + 1] != 'X')
            {
            ft_putchar(str[i],&indice);
            i++;
            }
            return (indice);
    } */
    if(str[i] == '\0')
         return indice;
    }
}
return indice;
}
 /* int main()
{
   // char *a = "abcdef";
    //char a = 'a';
   // int c = 5;
   // printf("ret:%d\n", printf("%d\n", 7));
   // printf("ret:%d\n", ft_printf("%d\n", 7));
    printf("test%%%14.s",  "ABC");
     printf("\n");
    ft_printf("test%%%14.s", "ABC");

   // ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
   // ft_printf("%-10c",a);
    // printf("\n");
    //prin
} */