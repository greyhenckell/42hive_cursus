//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

int ft_checker(char *c, char *set)
{
    int i = 0;
    while (set[i] != '\0')
    {
        if (c[i] == set[i])
        {
            i++;
        }
        else
            return 0;
    }
    return i;
}

size_t ft_checker_r(char *c, char *set, int len)
{

    size_t i = ft_strlen(set);
    size_t counter = 0;

    while (i > 0)
    {
        len--;
        i--;
        if (c[len] == set[i])
            counter++;
        else
            return 0;
    }
    return counter;
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *p1 = (char *)s1;
    char *pset = (char *)set;
    char *out;

    int c = 0;
    int i = 0;
    int y = 0;

    size_t lenstr = ft_strlen(p1);

    out = (char *)malloc((lenstr + 1) * sizeof(char));
    if (out == NULL)
        return NULL;

    while (p1[i] != '\0')
    {
        c = ft_checker(p1 + i, pset);
        if (c > 0)
            i = c + i;
        else
            break;
    }
    // update pointer, len string,
    p1 = p1 + i;
    lenstr = ft_strlen(p1);
    y = lenstr;
    i = 0;

    // use recursive function
    size_t r = ft_checker_r(p1, pset, lenstr);
    if (r == ft_strlen(pset))
    {
        lenstr = lenstr - r;
        r += ft_checker_r(p1, pset, lenstr);
    }
    y = y - r;
    while (i < y)
    {
        out[i] = p1[i];
        i++;
    }
    out[i] = '\0';
    return out;
}
/*
int main()
{
    printf("%s\n", strtrim("++----hola--++--", "++--")); //hola
}*/
