#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

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
        printf("--%d\n", (table[i]));
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

//run_algo(table, items);
//print_array(table, items);
//run from begining until pos
// check if exists > 1
int check_duplicate(char **str, int input_len)
{
    // ["2", "30", "40"]
    int temp[input_len];
    int item;

    //lst = (int **)malloc(sizeof(int *) * input_len);

    int  i = 1;
    int idx = 0;
    while(i < input_len)
    {
        //printf("parsing:%s\n", str[i]);
        if (contain_digit(str[i]))
        {
            item = ft_atoi(str[i]);
            //printf("%d\n", item);
            if( check_item(temp, item) == 0)
            {
                temp[idx] = item;
                idx++;
            }
        }  
        else
            return 0;
        i++;
    }
    //here is my stack :TEMP
    //printf("%d\n", idx);
    run_algo(temp, idx);
    print_array(temp, idx);
    return (1);
}

int main(int argc, char **argv)
{
    if (argc > 1)
        if (argc == 2)
            printf("check to split\n");
        else
        {
            if (!check_duplicate(argv, argc))
            {
                printf("error\n");
                return (1);
            }            
        }
    else
    {
        printf("Error\n");
        return (1);
    }
}