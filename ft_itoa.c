/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:48:09 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/07 16:21:31 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	integer_length(int n)
{
	int len;
	len = 0;
	if (n == INT_MIN)
		return (11);
	if (!n)
		return (1);
	if (n<0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
        {
		len++;
                n = n / 10;
        }
	return (len);
}

static	void	ft_putnbr(int n, char *out)
{
	int	mod;
	int	idx;
	int	sign;

	idx = 0;
	sign = 0;
	if (n == INT_MIN)
	{
		ft_strlcpy(out, "8463847412-", 12);
		return ;
	}
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (n > 0)
	{
		mod = n % 10;
		n = n / 10;
		out[idx++] = mod + 48;
	}
	if (sign)
		out[idx++] = '-';
	out[idx++] = '\0';
}

char	*ft_itoa(int n)
{
	char	*out;
	size_t	end;
	size_t	start;
	char 	temp;
	int	size;

	size = integer_length(n);
	out = (char *)malloc(size+1 * sizeof(char));
	if (out == NULL)
		return (NULL);
	ft_memset(out,0,size);
	if (n*-1 == 0)
	{
		out[0] = '0';
		out[1] = '\0';
		return out;
	}
	ft_putnbr(n, out);
	start = 0;
	end = ft_strlen(out)-1;
	while (start < end)
	{
		temp = out[start];
		out[start] = out[end]; 
		out[end] = temp;
		start++;
		end--;
	}
	return (out);
}
/*
int main()
{
	char *s = ft_itoa(0);
	printf("%s\n",s);
	free(s);
}*/
