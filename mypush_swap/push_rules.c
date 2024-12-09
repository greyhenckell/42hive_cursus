#include <stdio.h>

void check_swap(int *ptr)
{
    int temp;
    if (ptr[1])
    {
        temp = ptr[0];
        ptr[0] = ptr[1];
        ptr[1] = temp;        
    }
}

void check_push(int *stack, int items, int value)
{
    int i;

    i = 0;
    while(i < items && stack[i] != '\0')
    {
        stack[i] = 0;
        i++;
    }
    stack[i] = value;
}

void check_rotate(int *stack, int items)
{
    int i;


    i = 0;
    int first_item = stack[i];
    while( i< items && stack[i+1])
    {
        stack[i] = stack[i+1];
        i++;
    }
    stack[i] = first_item;
}