#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	r1;
	int	r2;

	r1 = ft_printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n",
			(void *)LONG_MIN, -100, -1988, 56645646, "welcome!!!");
	r2 = printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n", (void *)LONG_MIN,
			-100, -1988, 56645646, "welcome!!!");
	printf("fprint:%d vs rpprinnt:%d\n", r1, r2);

}
//cc ft_printf.c -I. -L. -lftprintf -o outmain.o