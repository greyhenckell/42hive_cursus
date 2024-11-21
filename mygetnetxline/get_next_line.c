#include "get_next_line.h"
#include <stdio.h>

// char 4bytes , default buffer_size = 1024
int check_new_line(t_line **ptrline)
{
    static char *temp;
    while ((*ptrline)->next != NULL)
    {
        temp = ft_strjoin(temp, (*ptrline)->content);
        (*ptrline) = (*ptrline)->next;
    }
    printf("%s", temp);
    return 0;
}
void append_to_line(t_line **ptrline, char *content_read)
{
    t_line *newitem_read;
    newitem_read = ft_newread(content_read);
    ft_lstadd_back(ptrline, newitem_read);
}
void create_line(char **ptrline, int fd)
{
    // create line
    char *temp = NULL;
    char *buff_content;
    int bytes_read;
    if (!temp)
        temp = malloc(1);
    if (!temp)
        return;
    free(temp);
    while (ft_strchr(*ptrline, '\n') == NULL)
    {

        // printf("--%s--\n", ft_strchr(temp, 10));
        // printf("##%s\n", *ptrline);
        temp = malloc((ft_strlen(*ptrline)) * sizeof(char));
        buff_content = malloc((BUFFER_SIZE + 1));
        if (!buff_content)
            return;
        bytes_read = read(fd, buff_content, BUFFER_SIZE);

        if (!bytes_read)
        {
            printf("nothing to read\n");
            free(buff_content);
            free(*ptrline);
            *ptrline = '\0';
            return;
        }
        else if (bytes_read == -1)
        {
            free(buff_content);
            return;
        }
        else
            buff_content[bytes_read] = '\0';
        //  join
        // printf("-> %dbytes\n", bytes_read);
        temp = ft_strjoin(*ptrline, buff_content);
        free(*ptrline);
        *ptrline = temp;
    }
}
char *get_next_line(int fd)
{
    static char *headline = NULL;
    // static char *remainder = NULL;
    char *out;
    char *temp;

    size_t rem_len;

    rem_len = 0;

    if (!headline)
        headline = malloc(1);
    if (!headline)
        return NULL;

    // create space for struct line
    if (fd < 0 || BUFFER_SIZE < 0)
        return NULL;

    // printf("input:%s\n", headline);
    create_line(&headline, fd);
    // printf("temp out:%s\n", headline);
    if (headline == NULL)
        return NULL;

    //   check if newline exists
    if (ft_strchr(headline, '\n'))
    {
        rem_len = ft_strlen(ft_strchr(headline, '\n') + 1);
        if (rem_len > 0)
        {
            out = malloc(((ft_strlen(headline) - rem_len) + 1) * sizeof(char));
            ft_strlcpy(out, headline, ft_strlen(headline) - rem_len);
            temp = malloc((rem_len + 1) * sizeof(char));
            if (temp)
                ft_strlcpy(temp, ft_strchr(headline, '\n') + 1, rem_len + 1);
            free(headline);
            headline = temp;
        }
        else
        {
            out = malloc(((ft_strlen(headline) - rem_len) + 1) * sizeof(char));
            ft_strlcpy(out, headline, ft_strlen(headline) - rem_len);
            free(headline);
            headline = NULL;
        }
    }

    return out;
}

int main()
{
    char *line;
    int fd = open("test1.txt", O_RDWR);

    while ((line = get_next_line(fd)) != NULL)
    {

        printf("out1:%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}