#include <stdio.h>

void iterate(char **stack)
{
    int i = 1;
    while (stack[i] != NULL)
    {
        printf("%s", stack[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
        iterate(argv);
    else
    {
        printf("Error\n");
        return (1);
    }
}