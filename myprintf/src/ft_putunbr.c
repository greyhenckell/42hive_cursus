void ft_putunbr(unsigned int n, char *out)
{
    int mod;
    int idx;

    idx = 0;

    while (n > 0)
    {
        mod = n % 10;
        n = n / 10;
        out[idx++] = mod + 48;
    }
    out[idx++] = '\0';
}
