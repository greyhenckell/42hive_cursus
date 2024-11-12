/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:38:44 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 18:02:20 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	pdest = (char unsigned *)dest;
	psrc = (char unsigned *)src;
	if (pdest > psrc)
	{
		while ((n--) > 0)
			pdest[n] = psrc[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
