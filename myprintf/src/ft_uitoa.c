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

#include "libft.h"

static int integer_length(unsigned int n)
{
    int len;

    len = 0;
    if (!n)
        return (1);

    while (n > 0)
    {
        len++;
        n = n / 10;
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

char *ft_uitoa(unsigned int n, char c)
{
    char *out;
    int size;

    size = integer_length(n);
    out = (char *)malloc((size + 1) * sizeof(char));
    if (out == NULL)
        return (NULL);
    ft_memset(out, 0, size);
    if (n == 0)
    {
        out[0] = '0';
        out[1] = '\0';
        return (out);
    }
    if (c == 'x' || 'X')
        ft_puthex(n, out);
    else
        ft_putunbr(n, out);
    reverse_string(out);
    return (out);
}
