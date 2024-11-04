/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:32:04 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/04 18:53:42 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <bsd/string.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		append_limit;
	int		i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	append_limit = size - dst_size - 1;
	if (dst_size > size)
		return (size + src_size);
	dst = dst + dst_size;
	while (i < append_limit)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst_size + src_size);
}
/*
int main()
{
	char source[] = "ABC";
	char dest[] = "";
	printf("src_len:%lu, dst_len:%lu\n", strlen(source), strlen(dest));
	size_t r = ft_strlcat(dest, source, 0);
	printf("%s\n", dest);
	printf("%zu\n", r);
	printf("--------------\n");
	char source2[] = "ABC";
        char dest2[] = "";
        size_t r2 = strlcat((void*)0, source2, 0);
        printf("%s\n", dest2);
        printf("%zu\n", r2);
}*/
