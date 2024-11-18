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

t_line *ft_newline(void *content)
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
    int i;
    char *p;
    p = (char *)s;

    i = 0;
    if (c == '\0')
        return "\0";
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
        {
            return (p + i);
        }
        i++;
    }
    return NULL;
}

void create_line(t_line **ptrline, int fd)
{
    // create line
    char *buff_content;
    int bytes_read;

    while (!(ft_strchr((*ptrline)->content, '\n')))
    {

        buff_content = malloc(BUFFER_SIZE + 1);
        if (!buff_content)
            return;

        bytes_read = read(fd, buff_content, BUFFER_SIZE);

        // printf("%d bytes read\n", bytes_read);
        if (!bytes_read)
        {
            // printf("nothing to read\n");
            free(buff_content);
            return;
        }
        else if (bytes_read == -1)
        {
            // printf("error reading\n");
            free(buff_content);
            return;
        }
        else
            buff_content[bytes_read] = '\0';
        // join
        ft_strjoin((*ptrline)->content, buff_content);
        printf("%s\n", (char *)(*ptrline)->content);
    }
    //(*ptrline)->content = buff_content;
}