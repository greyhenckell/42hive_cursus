#include <stdio.h>
#include "libft.h"

int main()
{
    char **result = ft_split("tripouille42", 0);
    int	i = 0;
    while (result[i])
    {
        printf("result:%s\n", result[i]);
        //if (strcmp(result[i], expected[i]))
        //    printf("error item %d", i + 1);
        free(result[i]);
        i++;
    }
    free(result);
}

//cc MAIN.c -I. -L. -lft -o outmain.o