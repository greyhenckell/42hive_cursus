#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

// cc ft_printf.c -Iincludes -L. -lft -o outmain.o

static int check_type(va_list p, char c)
{
    int count;

    if (c == 'c')
    {
        char val = (char)va_arg(p, int);
        count = 1;
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
        if (!val)
            val = "(null)";
        count = ft_strlen(val);
        write(1, val, count);
    }
    if (c == '%')
    {
        char val = '%';
        count = 1;
        write(1, &val, 1);
    }
    return count;
}

/*
static char ft_toupper_wrap(unsigned int i, char c)
{
    (void)i;
    return ((char)ft_toupper(c));
}*/

static int check_type_unsigned(va_list p, char c)
{
    int count;
    count = 0;

    if (c == 'u' || c == 'x' || c == 'X')
    {
        unsigned int val = va_arg(p, unsigned int);
        if (c == 'x')
        {
            ft_putnbr_base(val, 16, 97);
            count = ft_numlen(val, 16);
        }
        else if (c == 'X')
        {
            ft_putnbr_base(val, 16, 65);
            count = ft_numlen(val, 16);
        }
        else
        {
            ft_putnbr_base(val, 10, 0);
            count = ft_numlen(val, 10);
        }
    }

    if (c == 'p')
    {
        void *val = va_arg(p, void *);
        if (!val)
        {
            val = "(nil)";
            count = ft_strlen(val);
            write(1, val, count);
        }
        else
        {
            write(1, "0x", 2);
            ft_putnbr_base((unsigned long)val, 16, 97);
            count = ft_numlen((unsigned long)val, 16) + 2;
        }
    }
    return count;
}

int ft_printf(const char *fmt, ...)
{
    va_list arg_ptr;
    int len;
    int start;

    char *set = "%csdipuxX";
    va_start(arg_ptr, fmt);

    len = 0;
    start = 0;
    while (fmt[start] != '\0')
    {
        if ((fmt[start] == '%') && ft_strchr(set, fmt[start + 1]))
        {
            // call arg
            if (ft_strchr("%csdi", fmt[start + 1]))
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
/*
int main()
{
    int val = 20;
    ft_printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n", &val, -100, -1988, 56645646, "welcome!!!");
    printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n", &val, -100, -1988, 56645646, "welcome!!!");
    // int ftr = ft_printf("lowe_hex: %x, ptr:%p, unint:%u\n", 56645646, &val, -9223372036854775808);
    // ft_printf("lowe_hex: %x\n", -1);
    // printf("lowe_hex: %x\n", -1);

    // printf("fprint:%d vs rpprinnt:%d",ftr, rtr);
}
*/