/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:36:36 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/05 17:38:17 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nmemsize;
	int		*p;

	nmemsize = nmemb * size;
	if (nmemb != 0 && size != (nmemsize / nmemb))
		return (NULL);
	p = malloc(nmemsize);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, nmemsize);
	return (p);
}
