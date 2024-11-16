#include "ft_printf.h"

void ft_putnbr_base(long long n, int base, int c)
{
	char out;
	unsigned long long temp;

	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		temp = (unsigned long long)(-n);
	}
	else
		temp = (unsigned long long)n;

	if (temp >= (unsigned long long)base)
		ft_putnbr_base((long long)(temp / base), base, c);

	if ((temp % base) > 9)
		out = c + (temp % base) - 10;
	else
		out = (temp % base) + 48;
	write(1, &out, 1);
}
