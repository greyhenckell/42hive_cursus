/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:21 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/04 19:17:47 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
int	ft_atoi(const char *nptr)
{
	char	*p;
	long	out;
	int		i;
	int		sign;

	p = (char *)nptr;
	i = 0;
	out = 0;
	sign = 1;
	while ((p[i] >= 9 && p[i] <= 13) || p[i] == 32)
		i++;
	if ((p[i] == '+' || p[i] == '-'))
	{
		if (p[i] == '-')
			sign = -1;
		i = i + 1;
	}
	while (p[i] >= '0' && p[i] <= '9')
	{
		if (out > (INT_MAX-(p[i]-48))/10 )
			return (sign == 1?  INT_MAX: INT_MIN);
		out = (out * 10) + p[i]-48;
		i++;
	}
	return ((int)(out * sign));
}
/*
int main()
{

    printf("%d\n", ft_atoi("4000000000"));
    printf("%d\n", atoi("4000000000"));
}*/
