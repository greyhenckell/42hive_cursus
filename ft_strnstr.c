/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:42:08 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 11:42:27 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*pbig;
	char	*plit;

	pbig = (char *)big;
	plit = (char *)little;
	if (!(*pbig) || !len)
		return (NULL);
	if (!(*plit))
		return (pbig);
	i = 0;
	while (pbig[i] != '\0' && i < len)
	{
		if (pbig[i] == plit[0])
			if (!(ft_strncmp(pbig + i, plit, ft_strlen(plit) - 1)))
				return (pbig + i);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char *big = "dfgdfgf";
	const char *small = "fg";
	printf("%s\n",ft_strnstr(big, small, 10 ));
	printf("%s\n",strnstr(big, small, 10 ));
}*/
