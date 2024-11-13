/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:21 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/05 12:32:27 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	out;
	int		i;
	int		sign;

	i = 0;
	out = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i = i + 1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = (out * 10) + (nptr[i] - 48);
		if (out < 0 && sign == -1)
			return ((int)LONG_MIN);
		else if (out < 0 && sign == 1)
			return ((int)LONG_MAX);
		i++;
	}
	return ((int)(out * sign));
}
