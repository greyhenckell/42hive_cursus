/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:05:47 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/01 16:59:27 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <string.h>
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	if (c == 0)
		return (p + ft_strlen(s));
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == 0)
		return (NULL);
	return (p + i);
}
/*
int	main(void)
{
	printf("mmyv:%s\n", ft_strchr("hola sfgsgsereh", 50));
	printf("orig:%s\n", strchr("hola sfgsgsereh", 50));
}*/
