//#include <stdio.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *out;
    size_t i;

    if(start >= ft_strlen(s))
	len = 0;
    i = 0;
    out = (char *)malloc((len + 1) * sizeof(char));
    if (out == NULL)
	    return NULL;
    while (i < len)
    {
        out[i] = *(s + start + i);
        i++;
    }
    out[i] = '\0';
    return out;
}
/*
int main()
{
	char *str = "1234";
	char *ret = ft_substr(str, 10, 10);
	printf("%s\n",ret);
	free(ret);
}*/
