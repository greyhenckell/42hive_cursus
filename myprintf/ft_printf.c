#include <stdarg.h>

int	ft_printf(const char *, ...)
{

}


//va_list : var type 
//macros:
    // void va_start(va_list p, N): access to variadic fn args ,
    // type va_arg(va_list p, type): retrieve next arg with type <type> ,
    // va_end(va_list p) : end the variadic fn 
int main()
{
    ft_printf("%s", "hello");
}