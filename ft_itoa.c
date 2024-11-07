#include "libft.h"
#include <stdio.h>



void   ft_putnbr(int n, char *out)
{
	int mod;
	int idx;

	idx = 0;
	if (n == INT_MIN)
	{
		ft_strlcpy(out,"-2147483648", 11);
        return;
	}
    if (n < 0)
	{
		out[idx++] = '-';
		n = n*-1;
	}

	while(n>0)
	{
		mod = n%10;
		n = n/10;
		out[idx++] = mod+48;
	}
}

char	*ft_itoa(int n)
{
	char *out;
	out = (char *)malloc(12*sizeof(char));
	if (out == NULL)
			return (NULL);
	ft_putnbr(n, out);
	while()
		
	return out;	
}

int main()
{
	char *s = ft_itoa(5413);
	printf("%s\n",s);
}
