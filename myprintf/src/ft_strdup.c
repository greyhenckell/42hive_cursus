/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:23:12 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/31 11:39:19 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str_p;

	str_p = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (str_p == NULL)
		return (NULL);
	ft_strlcpy(str_p, src, ft_strlen(src) + 1);
	return (str_p);
}
