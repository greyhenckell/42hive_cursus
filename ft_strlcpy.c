/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:24 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 17:03:15 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int main()
{
    char input[] = "hola_es";
    char buf[20]="zz";
    int r = ft_strlcpy(buf, input, 0);
    printf("%s\n", buf);
    printf("%d\n", r);
}*/
