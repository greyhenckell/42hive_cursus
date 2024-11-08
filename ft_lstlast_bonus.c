/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:18:30 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/08 16:18:32 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void)
{
	t_list	*h;
	t_list	*out;

	h = ft_lstnew("A");
	h->next = ft_lstnew("B");
	h->next->next = ft_lstnew("C");
	out = ft_lstlast(h);
	printf("%s", (char *)out->content);
}
*/