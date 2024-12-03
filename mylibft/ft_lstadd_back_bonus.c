#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;
    t_list *ptr;
    ptr = *lst;
    if (*lst == NULL)
        *lst = new;
    else
    {
        while ((ptr)->next != NULL)
            (ptr) = (ptr)->next;
        (ptr)->next = new;
    }
}

/*int main()
{
    t_list *head;

    head = NULL;
    ft_lstadd_back(&head, ft_lstnew("A"));
    ft_lstadd_back(&head, ft_lstnew("B"));

    while (head != NULL)
    {
        printf("%s", (char *)head->content);
        head = head->next;
    }
}*/