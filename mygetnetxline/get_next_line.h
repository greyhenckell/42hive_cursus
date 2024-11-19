#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>



typedef struct s_line
{
    void *content;
    struct s_line *next;
} t_line;


t_line *ft_newline(void *content);
void create_line(t_line **ptrline, int fd);
char	*ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif 