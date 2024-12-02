#include <stdio.h>
#include "libft/libft.h"

void check_sa(int *ptr, int i, int *flag)
{
    int temp;
    if (ptr[i + 1])
    {
        // printf("%d vs %d\n", ptr[i], ptr[i + 1]);
        if (ptr[i] > ptr[i + 1])
        {
            printf("sa\n");
            *flag = 1;
            temp = ptr[i];
            ptr[i] = ptr[i + 1];
            ptr[i + 1] = temp;
        }
    }
}

void print_array(int *table, int items)
{
    int i = 0;
    while (i < items)
    {
        printf("--%d\n", table[i]);
        i++;
    }
}

void run_algo(int *table, int items)
{
    int col = 0;
    int flag = 0;
    while (col < items)
    {
        check_sa(table, col, &flag);
        // printf("--%d\n", table[col]);
        col++;
    }
    if (flag)
        run_algo(table, items);
}
void create_nodes(int items, char **stack)
{
    int i = 1;
    int idx = 0;
    int temp;

    int table[items];
    // int table2[items];

    while (stack[i] != NULL)
    {
        temp = ft_atoi(stack[i]);
        // printf("creating node for %d\n", temp);
        table[idx] = temp;
        i++;
        idx++;
    }

    run_algo(table, items);

    print_array(table, items);
}

int main(int argc, char **argv)
{
    if (argc > 1)
        if (argc == 2)
            printf("check to split\n");
        else
            create_nodes(argc - 1, argv);
    else
    {
        printf("Error\n");
        return (1);
    }
}