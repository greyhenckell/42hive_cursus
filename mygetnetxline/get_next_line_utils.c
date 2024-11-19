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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;

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

void create_line(t_line **ptrline, int fd)
{
    // create line
    char *buff_content;
    int bytes_read;
   
    int prevlen;
    
    
    while (!ft_strchr((char *)(*ptrline)->content , 10))    
    {
        
        printf("nlpos:%s\n", ft_strchr((*ptrline)->content , 10));
        prevlen = ft_strlen((*ptrline)->content);
        printf("prevlen:%d\n", prevlen);
        buff_content = malloc((BUFFER_SIZE+prevlen + 1)*sizeof(char));
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
        //else
        //    buff_content[bytes_read] = '\0';
        // join
        printf("cnt_w:%s\n", buff_content);
        //printf("temp:%s , endline:%d\n", (char *)(*ptrline)->content, ft_strchr((*ptrline)->content , '\n'));
        (*ptrline)->content = ft_strjoin((*ptrline)->content, buff_content);
        printf("%s\n", (char *)(*ptrline)->content);
    }
    
   
    //(*ptrline)->content = buff_content;
}