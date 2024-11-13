/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:26:41 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/07 15:08:35 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	uc;
	size_t			i;

	p = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
		if (p[i++] == uc)
			return ((void *)(p + i - 1));
	return (NULL);
}
