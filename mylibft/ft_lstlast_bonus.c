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

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*int main()
{
	t_list *head;
	t_list *res;

	int *val1 = malloc(sizeof(int));
	int *val2 = malloc(sizeof(int));

	*val1 = 10;
	*val2 = 20;

	head = ft_lstnew(val1);
	head->next = ft_lstnew(val2);
	// head->next->next = ft_lstnew((void *)3);

	res = ft_lstlast(head);
	printf("%d", *(int *)(res->content));
	// free(head->next->next);
	free(head->next);
	free(head);
}*/