//#include <stdio.h>
//#include <stdlib.h>

/*void callme(unsigned int i, char *str)
{
    (void)i;
    int len = ft_strlen(str);
    printf("%d\n", len);
    // printf("%s\n", str);
}*/

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    int i = 0;
    while (s[i] != '\0')
    {
        (*f)(i, &s[i]);
        i++;
    }
}
/*
int main()
{
    char inp[] = "hola";
    ft_striteri(inp, callme);
}*/
