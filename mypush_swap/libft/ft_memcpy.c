/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:36 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 12:57:18 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*psrc;
	char	*pdest;
	int		i;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	psrc = (char *)src;
	pdest = (char *)dest;
	i = 0;
	while (i < (int)n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
