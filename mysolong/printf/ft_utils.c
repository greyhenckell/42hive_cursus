/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:54:33 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/07 14:04:55 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_putnbr_base(long long n, int base, int c)
{
	int count;
	int tmp_count;
	char out;
	unsigned long long temp;

	count = 0;
	if (n < 0 && base == 10)
	{
		count = write(1, "-", 1);
		if (count == -1)
			return (-1);
		temp = (unsigned long long)(-n);
	}
	else
		temp = (unsigned long long)n;
	if (temp >= (unsigned long long)base)
		ft_putnbr_base((long long)(temp / base), base, c);
	if ((temp % base) > 9)
		out = c + (temp % base) - 10;
	else
		out = (temp % base) + 48;
	if ((tmp_count = write(1, &out, 1)) == -1)
		return (-1);
	count += tmp_count;
	return (count);
}

int ft_putchar(char c)
{
	int count;

	count = write(1, &c, sizeof(c));
	return count;
}
