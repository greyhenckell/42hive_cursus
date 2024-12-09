#include <stdio.h>

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