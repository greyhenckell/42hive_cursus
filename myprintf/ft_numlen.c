int ft_numlen(unsigned long long n, int base)
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