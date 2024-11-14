/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:54:33 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/07 14:04:55 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	out = (char *)malloc((len + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while (i < len)
	{
		out[i] = *(s + start + i);
		i++;
	}
	out[i] = '\0';
	return (out);
}
