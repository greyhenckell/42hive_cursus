/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:38:08 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/01 16:43:39 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			i;

	if (n == 0)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *e1 = "welcome ";
	char *e2 = "welpole";
	printf("%d\n", ft_memcmp(e1,e2,5));
	printf("%d\n", memcmp(e1,e2,5));
	printf("-------\n");
	long setone[5] = { 1, 3, 5, 7, 9 };
	long settwo[5] = { 3, 2, 5, 7, 8 };
	printf("%d\n", memcmp(&setone, &settwo,5));
	printf("%d\n", ft_memcmp(&setone, &settwo,5));
}*/
