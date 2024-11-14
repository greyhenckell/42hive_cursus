/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:48:09 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/08 09:30:00 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int integer_length(unsigned long n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void reverse_string(char *out)
{
	unsigned int start;
	unsigned int end;
	char temp;

	start = 0;
	end = ft_strlen(out) - 1;
	while (start < end)
	{
		temp = out[start];
		out[start] = out[end];
		out[end] = temp;
		start++;
		end--;
	}
}

char *ft_ultoa(unsigned long n, char c)
{
	char *out;
	int size;

	size = integer_length(n);
	if (n == 0)
	{
		out = (char *)malloc(2 * sizeof(char));
		if (out)
			ft_strlcpy(out, "0", 2);
		return (out);
	}
	out = (char *)malloc((size + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	ft_memset(out, 0, size);

	if (c == 'x' || c == 'X')
		ft_putlonghex(n, out);
	else
		ft_putunbr(n, out);
	reverse_string(out);
	return (out);
}
