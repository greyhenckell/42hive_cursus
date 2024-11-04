/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:54:48 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 16:08:37 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t		i;
	unsigned char	uc;

	if (n == 0)
		return (s);
	
	p = (unsigned char *)s;
	i = 0;
	uc = (unsigned char)c;
	while (i < n)
		p[i++] = uc;
	return (s);
}
/*
int main()
{
	char src[] = "welcome well";
	char src2[] = "welcome well";

	printf("%lu vs %lu\n", sizeof(src), sizeof(src2));
	ft_memset(src, -10, ft_strlen(src));
	printf("%s\n", src);
	printf("------\n");
	memset(src2, -10, ft_strlen(src2));
	printf("%s\n", src2);
	if (ft_strncmp(src,src2, ft_strlen(src)) == 0)
		printf("OK\n");
}*/
