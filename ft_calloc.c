#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    int *p;

    if (nmemb || size == 0)
    {
        nmemb = 1;
        size = 1;
    }
    // return NULL;

    p = malloc(nmemb * size);
    if (p == NULL)
        return NULL;
    ft_memset(p, 0, size);    
    return p;
}

int main()
{
    // printf("%ld, %ld", sizeof(char), sizeof(int));

    char s[5] = "hola";
    char *ptr;

    ptr = s;

    printf("%s\n", ptr);
    ptr = (char *)ft_calloc(0, 0);

    int i = 0;
    while (i < 4)
    {
        printf("%c ", ptr[i]);
        i++;
    }
}
