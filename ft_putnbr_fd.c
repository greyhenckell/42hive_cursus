#include <unistd.h>
#include <stdio.h>
void ft_putnbr_fd(int n, int fd)
{
    long m;
    int mod;
    int q;
    char out;

    if (n < 0)
    {
        m = n * -1;
        write(fd, "-", 1);
    }
    else
        m = n;

    q = m / 10;
    mod = m % 10;
    if ((m / 10) > 9)
    {

        ft_putnbr_fd(q, 1);
        out = mod + '0';
        write(fd, &out, 1);
    }
    else
    {
        out = q + '0';
        write(fd, &out, 1);
        out = mod + '0';
        write(fd, &out, 1);
    }
}

int main()
{
    ft_putnbr_fd(-43179778, 1);
}