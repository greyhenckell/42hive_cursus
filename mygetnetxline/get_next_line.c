#include "get_next_line.h"
#include <stdio.h>

// char 4bytes , default buffer_size = 1024

char *get_next_line(int fd)
{
    static t_line *headline;

    // create space for struct line

    if (fd < 0 || BUFFER_SIZE < 0)
        return NULL;

    headline = ft_newline("");
    create_line(&headline, fd);

    return headline->content;
}

int main()
{
    char *buff_content;
    int fd = open("test1.txt", O_RDWR);
    printf("%d\n", fd);
    while (!buff_content)
    {
        buff_content = get_next_line(fd);
        printf("%s\n", buff_content);
    }
    close(fd);
    return 0;
}