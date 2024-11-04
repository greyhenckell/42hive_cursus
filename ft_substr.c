//#include <stdio.h>
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *out;
    char *temp;
    size_t i;

    i = 0;
    out = (char *)malloc((len + 1) * sizeof(char));
    if (out == NULL)
	    return NULL;
    temp = (char *)s;
    while (i < len)
    {
        out[i] = *(temp + start + i);
        i++;
    }
    out[i] = '\0';
    return out;
}
/*
int main()
{
    // ft_substr("holaCOMOhola", 4, 4);
    printf("%s\n", ft_substr("holaCOMOhola", 4, 4));
}*/
