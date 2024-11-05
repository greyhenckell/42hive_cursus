//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

int count_items(char *s, char split)
{
    int i;
    int c;

    i = 0;
    c = 1;
    while (s[i] != '\0')
    {
        if (s[i] == split)
            c++;
        i++;
    }
    return c;
}

char *ft_str_alloc(const char *src, size_t size)
{
    size_t i;
    char *dst;
    i = 0;
    dst = (char *)malloc((size + 1) * sizeof(char));
    while (i < size)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

void mover(char *ps, char c, char **out, char *temp, int size, int idx)
{
    // char *ptrcpy;
    int i = 0;
    if (ft_strchr(ps, c))
    {
        while (ps[i] != '\0' && ps[i] != c)
            i++;

        // copy
        temp = ft_str_alloc(ps, i);
        out[idx] = temp;
        // next to call
        mover(ps + i + 1, c, out, temp, size, idx + 1);
    }
    else
    {
        temp = ft_str_alloc(ps, ft_strlen(ps));
        out[size - 1] = temp;
        return;
    }
}

char **ft_split(char const *s, char c)
{
    char *ps;
    char **out;
    char *temp = NULL;
    // int i;

    char *nptr = NULL;

    int array_size;

    ps = (char *)s;
    array_size = count_items(ps, c);

    out = (char **)malloc((array_size + 1) * sizeof(char *));
    if (out == NULL)
        return NULL;

    mover(ps, c, out, temp, array_size, 0);

    out[array_size + 1] = nptr;
    free(temp);
    return out;
}
/*
int main()
{
    char **result;
    result = ft_split("_hei_hola___bebezote_wha_ma_", '_'); // '', 'hola', 'como'
    int i = 0;
    while (result[i])
    {
        printf("result: %s \n", result[i]);
        i++;
    }
    free(result);
}*/
