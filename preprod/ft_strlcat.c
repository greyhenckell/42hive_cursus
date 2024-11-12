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

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_size;
	size_t src_size;

	if (!dst && size == 0)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	
	if (dst_size >= size)
		return (size + src_size);

	i = 0;

	while (src[i] && (i < size - dst_size - 1))
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
