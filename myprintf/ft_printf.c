#include <stdarg.h>
#include "libft.h"
#include <stdio.h>

static int check_type(va_list p, char c)
{
    int count;
    count = 0;
    if (c == 'c')
    {
        char val = va_arg(p, int);
        count++;
        ft_putchar(val);
    }

    if (c == 'd' || c == 'i')
    {
        int val = va_arg(p, int);
        char *s = ft_itoa(val);
        count = ft_strlen(s);
        write(1, s, count);
        free(s);
    }
    if (c == 's')
    {
        char *val = va_arg(p, char *);
        count = ft_strlen(val);
        write(1, val, count);
    }
    return count;
}

static char ft_toupper_wrap(unsigned int i, char c)
{
    (void)i;
    return ((char)ft_toupper(c));
}

static int check_type_unsigned(va_list p, char c)
{
    int count;
    count = 0;

    if (c == 'u' || c == 'x' || c == 'X')
    {
        unsigned int val = va_arg(p, unsigned int);
        char *s = ft_uitoa(val, c);
        count = ft_strlen(s);
        if (c == 'X')
        {
            char *m = ft_strmapi(s, ft_toupper_wrap);
            write(1, m, count);
            free(m);
        }
        else
            write(1, s, count);
        free(s);
    }
    return count;
}

int ft_printf(const char *fmt, ...)
{
    va_list arg_ptr;
    int len;
    int start;

    char *set = "csdipuxX";
    va_start(arg_ptr, fmt);

    len = 0;
    start = 0;
    while (fmt[start] != '\0')
    {
        if ((fmt[start] == '%') && ft_strchr(set, fmt[start + 1]))
        {
            // call arg
            if (ft_strchr("csdi", fmt[start + 1]))
                len += check_type(arg_ptr, fmt[++start]);
            else
                len += check_type_unsigned(arg_ptr, fmt[++start]);
        }
        else
        {
            ft_putchar(fmt[start]);
            len++;
        }
        start++;
    }

    va_end(arg_ptr);

    return len;
}

// va_list : var type
// macros:
//  void va_start(va_list p, N): access to variadic fn args ,
//  type va_arg(va_list p, type): retrieve next arg with type <type> ,
//  va_end(va_list p) : end the variadic fn
int main()
{
    ft_printf("dec:%%%d, X: %X, h:%x, str:%s\n", -100, -1988, 56645646, "welcome!!!");
    printf("dec:%%%d, X: %X, h:%x, str:%s\n", -100, -1988, 56645646, "welcome!!!");
}