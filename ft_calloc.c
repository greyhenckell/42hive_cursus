/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:36:36 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 10:19:51 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	long	nmemsize;
	int		*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	nmemsize = nmemb * size;
	p = malloc(nmemsize);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, nmemsize);
	return (p);
}
/*
int main()
{
    // printf("%ld, %ld", sizeof(char), sizeof(int));

    char s[] = "hola welcome";
    char *ptr;

    ptr = s;

    printf("%s\n", ptr);
    ptr = (char *)ft_calloc(50000000, 500);

    int i = 0;
    while (i < 20)
    {
        printf(":%c\n", ptr[i]);
        i++;
    }
    free(ptr);
}*/
