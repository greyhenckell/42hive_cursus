/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:36:36 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/05 16:18:57 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	nmemsize;
	int				*p;

	if (nmemb != 0 && size > (UINT_MAX / nmemb))
		return (NULL);
	if (!nmemb || !size)
		nmemsize = 1;
	else
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
    char s[] = "hola welcome";
    char *ptr;

    ptr = s;

    printf("%s\n", ptr);
    ptr = (char *)calloc(50000000000000, 10);
    if (ptr == NULL)
	printf("calloc not allocated\n");
    else
    	printf("ptr created\n");
    int i = 0;
    while (i < 20)
    {
        printf(":%c\n", ptr[i]);
        i++;
    }
    free(ptr);
}*/
