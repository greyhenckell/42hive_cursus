/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:50:45 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/08 09:50:46 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = NULL;
	out = (t_list *)malloc(sizeof(t_list));
	if (out == NULL)
		return (NULL);
	out->content = content;
	out->next = NULL;
	return (out);
}
