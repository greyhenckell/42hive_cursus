#include "libft/libft.h"

int contain_digit(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if ( !ft_isdigit(str[i]) )
            return 0;
        i++;
    }
    return(1);
}



int check_item(int *table, int item)
{
    int i = 0;
    
    while(table[i])
    {
        if (  (table[i]) == item)
            return (1);
        i++;
    }
    return (0);
}