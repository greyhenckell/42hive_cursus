/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:21 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 09:49:45 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (p[i] == 32)
		i++;
	if ((p[i] == '+' || p[i] == '-'))
	{
		if (p[i] == '-')
			sign = -1;
		i = i + 1;
	}
	while (p[i] >= '0' && p[i] <= '9')
	{
		out = (p[i] - '0') + (out * 10);
		i++;
	}
	return (out * sign);
}
/*
int main()
{

    printf("%d\n", ft_atoi("- 21474836489"));
    printf("%d\n", atoi("- 21474836489"));
}*/
