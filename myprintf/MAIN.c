#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int r1;
	int r2;

	/*r1 = ft_printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n",
				   (void *)LONG_MIN, -100, -1988, 56645646, "welcome!!!");
	r2 = printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n", (void *)LONG_MIN,
				-100, -1988, 56645646, "welcome!!!");
	printf("fprint:%d vs rpprinnt:%d\n", r1, r2);*/

	/*int orig_stdout = dup(STDOUT_FILENO);
	fclose(stdout);
	int ret = ft_printf("%p", (void *)LONG_MIN);
	stdout = (FILE *)fdopen(orig_stdout, "w");
	printf("%d\n", ret);*/
	r1 = ft_printf("test h%h\n");
	r2 = printf("test h%h\n");

	printf("%d %d", r1, r2);
}
// cc MAIN.c -I. -L. -lftprintf -o outmain.o