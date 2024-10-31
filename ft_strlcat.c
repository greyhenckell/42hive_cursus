/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:32:04 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 13:05:22 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	append_limit;
	int	i;
	int	dst_size;

	i = 0;
	dst_size = ft_strlen(dst);
	append_limit = size - dst_size - 1;
	dst = dst + dst_size;
	while (i < append_limit)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst_size + ft_strlen(src));
}
/*
int main()
{
	char source[] = "_welcome";
	char dest[] = "hola";
	size_t r = strlcat(dest, source, strlen(source)+1);
	printf("%s\n", dest);
	printf("%zu\n", r);
}*/
