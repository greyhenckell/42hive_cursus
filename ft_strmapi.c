#include <stdio.h>
#include <stdlib.h>

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char ft_toupper(unsigned int i, char c)
{
    if (i)
        return ((char)(int)c - 32);
    return c;
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *ps;
    char *out;
    ps = (char *)s;

    int i = 0;

    out = (char *)malloc((ft_strlen(ps) + 1) * sizeof(char));
    if (out == NULL)
        return NULL;
    while (ps[i] != '\0')
    {

        out[i] = (*f)(i, ps[i]);
        // printf("%c\n", );
        i++;
    }
    out[i] = '\0';
    return out;
}

int main()
{
    printf("%s\n", ft_strmapi("hola", ft_toupper));
}