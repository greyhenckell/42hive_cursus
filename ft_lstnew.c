#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *out;

    out = NULL;

    out = (t_list *)malloc(sizeof(t_list));
    if (out == NULL)
        return NULL;

    out->content = content;
    out->next = NULL;
    return out;
}
/*
int main()
{
    t_list *test = NULL;
    test = ft_lstnew("hola");
    printf("%p\n", test);
    free(test);
}
*/
