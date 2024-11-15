#include "ft_printf.h"
#include <stdio.h>
void	ft_putnbr_base(unsigned long long n, int base)
{
	char	out;

	if (n > (unsigned long long)(base - 1))
		ft_putnbr_base(n / base, base);

	if ((n % base) > 9 && base == 16)
		out = 'a' + (n % base) - 10;
	else
		out = (n % base) + 48;
	write(1, &out, 1);
	
}
