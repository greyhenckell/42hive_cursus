/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:42:08 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/05 15:06:17 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lenlit;

	if (!big && len == 0)
		return (NULL);
	lenlit = ft_strlen(little);
	if (lenlit == 0)
		return ((char *)(big));
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			if (!(ft_strncmp(big + i, little, lenlit)))
			{
				i += lenlit;
				if (i > len)
					return (NULL);
				return ((char *)(big + i - lenlit));
			}
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *big = "oh no not the empty string !";
	char *small = "";
	//char *small = "";
	printf("len:%lu\n", strlen(big));
	printf("%s\n",ft_strnstr((void*)0, small, 0 ));
	printf("%s\n",strnstr((void*)0, small, 0 ));
}*/
