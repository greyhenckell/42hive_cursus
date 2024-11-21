#include "get_next_line.h"
#include <stdio.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t len;

    len = ft_strlen(src);
    i = 0;
    if (size == 0)
        return (len);
    while (src[i] && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len;
    size_t s2_len;
    char *ptr;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
    if (ptr == NULL)
        return (NULL);
    ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
    ft_strlcpy(ptr + s1_len, s2, ft_strlen(s2) + 1);
    return ((char *)ptr);
}

char *ft_strchr(const char *s, int c)
{
    char *p;
    size_t i;

    p = (char *)s;
    if (c == 0)
        return (p + ft_strlen(s));
    i = 0;
    while (s[i] != (char)c && s[i] != '\0')
        i++;
    if (s[i] == 0)
        return (NULL);
    return (p + i);
}

t_line *ft_newread(void *content)
{
    t_line *out;

    out = NULL;
    out = (t_line *)malloc(sizeof(t_line));
    if (out == NULL)
        return (NULL);
    out->content = content;
    out->next = NULL;
    return (out);
}

void ft_lstadd_back(t_line **lst, t_line *new)
{
    t_line *p;
    p = *lst;
    while (p->next != NULL)
        p = p->next;

    p->next = new;
}
