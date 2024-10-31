/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:26:41 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 12:50:14 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (p[i] != '\0' && i < n)
		if (p[i++] == c)
			return (p + i - 1);
	return (NULL);
}
/*
int main()
{
	char s[] = "hi hiver";
	printf("%s\n",ft_memchr(s, 'p', 5));
}*/
