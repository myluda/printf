#include<stdio.h>
#include "ft_printf.h"

int	main()
{
  int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
//ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c);
ft_printf("%-.d\n",0);
printf("%-.d\n",0);
/*printf("\n");
printf("\n");*/
 /* printf("\n%d\n",printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c));
 printf("\n%d\n",ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c)); */
 //printf("%d",printf("%*.*d\n",-4,0,5));
  return(0);
}
