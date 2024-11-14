#include "ft_printf.h"

void ft_putlonghex(unsigned long n, char *out)
{
	unsigned long mod;
	int idx;

	idx = 0;

	while (n > 0)
	{
		mod = n % 16;
		n = n / 16;
		if (mod > 9)
		{
			out[idx++] = 'a' + mod - 10;
		}
		else
			out[idx++] = mod + 48;
	}
	out[idx++] = '\0';
}
