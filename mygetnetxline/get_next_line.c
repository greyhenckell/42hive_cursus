#include "get_next_line.h"
#include <stdio.h>

// char 4bytes , default buffer_size = 1024

char *get_next_line(int fd)
{
    static t_line *headline;

    // create space for struct line
    printf("inside_get_next: %d\n", fd);
    if (fd < 0 || BUFFER_SIZE < 0)
        return NULL;

    // char *bf = malloc(BUFFER_SIZE*sizeof(char));
    headline = ft_newread("");
    create_line(&headline, fd);

    return headline->content;
}

int main()
{
    char *buff_content = NULL;
    int fd = open("test1.txt", O_RDWR);
    while (!buff_content)
    {
        buff_content = get_next_line(fd);
        printf("%s\n", buff_content);
    }
    close(fd);
    return 0;
}