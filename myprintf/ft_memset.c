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

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;
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
