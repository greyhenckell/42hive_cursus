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
#include <stdio.h>

static	void	ft_putnbr(int n, char *out)
{
	int	mod;
	int	idx;

	idx = 0;
	if (n == INT_MIN)
	{
		ft_strlcpy(out, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		out[idx++] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		mod = n % 10;
		n = n / 10;
		out[idx++] = mod + 48;
	}
	out[idx++] = '\0';
}

char	*ft_itoa(int n)
{
	char	*out;
	char	*temp;
	int	len;
	int	idx;

	out = (char *)malloc(12 * sizeof(char));
	if (out == NULL)
		return (NULL);
	ft_putnbr(n, out);
	temp = out;
	idx = 0;
	if (temp[0] == '-')
	{
		out[idx++] = '-';
		len = ft_strlen(temp+1);
		printf("%d\n",len);
	}
	else
		len = ft_strlen(temp);
	while ( len > 0)
	{
		out[idx++] = temp[len];
		len--;	
	}
	return (out);
}

int main()
{
	char *s = ft_itoa(-623);
	printf("%s\n",s);
}
