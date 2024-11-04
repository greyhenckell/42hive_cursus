/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:24 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/04 13:21:42 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while (src[i] && i < size-1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int main()
{
    char *input = "AAAA";
    char buf[]="zzzzzzzzzz";
    printf("bufsize:%lu vs src_size:%lu\n", strlen(buf), strlen(input));
    int r = ft_strlcpy(buf, input, strlen(buf));
    printf("%s\n", buf);
    printf("%d\n", r);
    printf("---------\n");
    char *input2 = "AAAA";
    char buf2[] = "zzzzzzzzzz";
    int r2 = strlcpy(buf2, input2, strlen(buf2));
    printf("%s\n", buf2);
    printf("%d\n", r2);
}*/
