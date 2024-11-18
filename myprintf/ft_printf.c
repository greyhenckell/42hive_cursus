/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:22:35 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/18 14:22:37 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

// cc ft_printf.c -I. -L. -lftprintf -o outmain.o

static int	check_pointer(va_list p, char c)
{
	int		count;
	void	*str;

	if (c == 's')
	{
		str = (char *)va_arg(p, char *);
		if (!str)
			str = "(null)";
		count = ft_strlen(str);
		write(1, str, count);
	}
	if (c == 'p')
	{
		str = (void *)va_arg(p, void *);
		if (!str)
		{
			str = "(nil)";
			write(1, str, ft_strlen(str));
			return (ft_strlen(str));
		}
		write(1, "0x", 2);
		ft_putnbr_base((unsigned long)str, 16, 97);
		count = ft_unsigned_numlen((unsigned long)str, 16) + 2;
	}
	return (count);
}

static int	check_type(va_list p, char c)
{
	int	count;
	int	val;

	count = 1;
	if (c == 'c')
	{
		val = (int)va_arg(p, int);
		write(1, &val, 1);
	}
	if (c == 'd' || c == 'i')
	{
		val = (int)va_arg(p, int);
		ft_putnbr_base(val, 10, 0);
		count = ft_numlen(val, 10);
	}
	if (c == 's')
		count = check_pointer(p, c);
	if (c == '%')
	{
		val = '%';
		write(1, &val, 1);
	}
	return (count);
}

static int	check_type_unsigned(va_list p, char c)
{
	int				count;
	unsigned int	val;

	count = 0;
	if (c == 'u' || c == 'x' || c == 'X')
	{
		val = (unsigned int)va_arg(p, unsigned int);
		count = ft_unsigned_numlen(val, 16);
		if (c == 'x')
			ft_putnbr_base(val, 16, 97);
		else if (c == 'X')
			ft_putnbr_base(val, 16, 65);
		else
		{
			ft_putnbr_base(val, 10, 0);
			count = ft_numlen(val, 10);
		}
	}
	if (c == 'p')
		count = check_pointer(p, c);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg_ptr;
	int		len;
	int		start;

	va_start(arg_ptr, fmt);
	len = 0;
	start = 0;
	while (fmt[start] != '\0')
	{
		if ((fmt[start] == '%') && ft_strchr("%csdipuxX", fmt[start + 1]))
		{
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
	return (len);
}
/*
int	main(void)
{
	int	r1;

	//int	r2;
	r1 = ft_printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n",
			(void *)LONG_MIN, -100, -1988, 56645646, "welcome!!!");
	r2 = printf("pointer: %p dec:%%%d, X: %X, h:%x, str:%s\n", (void *)LONG_MIN,
			-100, -1988, 56645646, "welcome!!!");
	printf("fprint:%d vs rpprinnt:%d", r1, r2);
	r1 = ft_printf(" NULL %s NULL\n", NULL);
	//r2 = printf(" NULL %s NULL ", NULL);
	printf("fprint:%d ", r1);
}
*/