/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:26:41 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 17:25:56 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char uc;
	size_t	i;

	p = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
		if (p[i++] == uc)
			return (void *)(p + i - 1);
	return (NULL);
}
/*
int main()
{
	char s[] = "hi hiver";
	printf("%s\n", (char *)ft_memchr(s, 0, sizeof(s)));
}*/
