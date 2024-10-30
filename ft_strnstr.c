/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:42:08 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/30 18:16:13 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int	k;
	char	*pbig;
	char	*plit;

	pbig = (char *)big;
        plit = (char *)little;

	if (!(*plit))
		return pbig;
	i = 0;
	k = 0;
	while(pbig[i] != '\0' && i < len )
	{
		if(pbig[i] == plit[k])
		{
			printf("i:%zu\n", i);
			printf("%s\n", pbig+i);
			k = ft_strncmp(pbig+i, plit, ft_strlen(plit));
			printf("myk: %d\n",k);
		}
		else
			i++;
	}
	//printf("1stoccurrence: %s\n", pbig+i);
	return NULL;
}

int main()
{
	const char *big = "FooBa Bar Baz";;
	const char *small = "Bar";
	//printf("%zu\n",ft_strlen(small));
	//printf("%d\n",ft_strncmp(big,"Bar",3));
	printf("%s\n",ft_strnstr(big, small, 40 ));
	printf("%s\n",strnstr(big, small, 40 ));
}
