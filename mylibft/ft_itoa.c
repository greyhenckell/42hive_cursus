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
#include <stdio.h>


static int	integer_length(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		return (11);
	if (!n)
		return (1);
	if (n < 0)
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

int num_abs(int n)
{
	if (n<0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		size;
	int		i;

	i = 0;
	size = integer_length(n);
	//printf("%d %d\n", size, n);
	out = (char *)malloc((size + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	out[size] = '\0';
	if (n == 0)
		out[0] = '0';
	if (n < 0)
	{
		out[0] = '-';
		i++;
	}
	while(size -1 >= i)
	{
		out[size-1] = num_abs(n %10) +'0';
		n = n / 10;		
		size--;
	}	
	return (out);
}
