void ft_puthex(unsigned int n, char *out)
{
    int mod;
    int idx;

    idx = 0;

    while (n > 0)
    {
        mod = n % 16;
        n = n / 16;
        if (mod > 9)
        {
            mod += 87;
            out[idx++] = (char)mod;
        }
        else
            out[idx++] = mod + 48;
    }
    out[idx++] = '\0';
}
