#include <stdarg.h>
#include "libft.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}

int	ft_printf(const char *fmt, ...)
{
    va_list arg_ptr;

    char *set = "cspdiuxX";

    va_start(arg_ptr, fmt);
    int start;
    int end;
    start = 0;
    while(fmt[start] != '\0')
    {
        if (fmt[start] == '%' &&  ft_strchr(set, fmt[start+1]))
        {
            //call arg
            char *val = va_arg(arg_ptr, char *);
            write(1, val, ft_strlen(val));
        }

        else
            ft_putchar(fmt[start]);
        start++;
    }
    
    //char *set = "%cspdiuxX";
    //printf("%s", ft_strchr(fmt, '%'));

    va_end(arg_ptr);

    return 0;
}


//va_list : var type 
//macros:
    // void va_start(va_list p, N): access to variadic fn args ,
    // type va_arg(va_list p, type): retrieve next arg with type <type> ,
    // va_end(va_list p) : end the variadic fn 
int main()
{
    ft_printf("testing : %s t2: %s \n", "myprinter", "wonder");
}