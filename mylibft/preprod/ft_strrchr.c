/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:19:38 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 17:46:38 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	len;

	p = (char *)s;
	len = ft_strlen(s);
	if (c == 0)
		return (p + len);
	while ((len--) > 0)
	{
		if (p[len] == c)
			return (p + len);
	}
	return (NULL);
}
