/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:37:22 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/06 15:45:56 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	i = 0;
	out = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
