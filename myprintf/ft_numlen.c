int ft_unsigned_numlen(unsigned long n, int base)
{
	int len;

	if (n == 0)
		return 1;
	len = 0;

	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int ft_numlen(long long n, int base)
{
	int len;

	if (n == 0)
		return 1;
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}