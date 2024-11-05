#include <unistd.h>

void ft_putendl_fd(char *s, int fd)
{
    int i = 0;

    while (s[i] != '\0')
        i++;
    s[i] = '\n';
    s[i + 1] = '\0';
    write(fd, s, i + 1);
}
/*
int main()
{
    char s[] = "holaaa";
    ft_putendl_fd(s, 1);
}
*/