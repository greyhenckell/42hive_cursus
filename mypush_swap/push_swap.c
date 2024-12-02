#include <stdio.h>
#include "libft/libft.h"

void check_sa(int *ptr, int i)
{
    int temp;
    int i=0;
    if (ptr[i] > ptr[i+1])
    {
        temp = ptr[i];
        ptr[i] = ptr[i+1];
        ptr[i+1] = temp;
    }

void create_nodes(int items ,char **stack)
{
    int i = 1;
    int idx = 0 ;
    int temp;

    int table[items];
    //int table2[items];
    
    while (stack[i] != NULL)
    {
        
        temp = ft_atoi(stack[i]);
        printf("creating node for %d\n", temp);
        table[idx] = temp;        
        i++;
        idx++;
    }
    check_sa(table);
    //int row = 0;
    /*int col = 0;
  
    while(col < items)
    {
            //printf("%d %d %d\n", row, col, items);
            printf("--%d\n", table[col]);
            col++;
    }*/
}

int main(int argc, char **argv)
{
    if (argc > 1)
        if (argc == 2)
            printf("check to split\n");
        else
            create_nodes(argc-1, argv);
    else
    {
        printf("Error\n");
        return (1);
    }
}