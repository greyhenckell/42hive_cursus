//#include <stdio.h>
//#include <stdlib.h>

int ft_atoi(const char *nptr)
{
    char *p;
    int i;

    long out;
    int sign;

    p = (char *)nptr;
    i = 0;
    out = 0;
    sign = 1;
    while (p[i] == 32)
    {
        i++;
    }

    if ((p[i] == '+' || p[i] == '-'))
    {
        if (p[i] == '-')
            sign = -1;
        i = i + 1;
    }

    while (p[i] >= '0' && p[i] <= '9')
    {
        out = (p[i] - '0') + (out * 10);
        i++;
    }
    return out * sign;

    return 0;
}
/*
int main()
{

    printf("%d\n", ft_atoi("4000000000"));
    printf("%d\n", atoi("4000000000"));
}*/

