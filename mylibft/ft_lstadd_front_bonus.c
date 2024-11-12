/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:59:18 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/08 15:59:21 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list  *h;
	t_list **lst;

	lst = &h;

	h = ft_lstnew("B");
	h->next = ft_lstnew("C");
	ft_lstadd_front(lst, ft_lstnew("A"));
	while (h != NULL)
	{
		printf("%s ", (char *)h->content);
		h = h->next;
	}
}*/
