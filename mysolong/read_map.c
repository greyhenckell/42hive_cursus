#include "so_long.h"
#include <stdio.h>

size_t ft_gnl_strlen(const char *s)
{
    size_t i;
    size_t f = 0;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
            f++;

        i++;
    }
    return (i - f);
}
int is_rectangular(int prevlen, int currentlen)
{
    // printf("%d %d \n", prevlen, currentlen);
    if ((prevlen - currentlen) != 0)
        return 1;
    return 0;
}

void duplicate_characters(char *line, int *rules)
{
    if (!line || !rules)
        return;
    int i = 0;
    while (line[i] != '\0' && *rules <= 3)
    {
        if (line[i] == 'C' || line[i] == 'P' || line[i] == 'E')
            (*rules)++;
        i++;
    }
}

void free_map(t_map *map, int indx)
{
    if (map && map->map)
    {
        while (indx-- > 0)
        {
            free(map->map[indx]);
        }
        free(map->map);
        map->map = NULL;
    }
}

int read_map(char *src, t_map *map)
{
    char *line = NULL;
    int rules = 0;

    if (!src || !map)
        return (1);

    int fd = open(src, O_RDONLY);
    if (fd < 0)
        return (1);

    int numlines = 0;
    int prev_lenline = 0;
    map->map = NULL;

    map->map = (char **)malloc((5) * sizeof(char *));
    ft_memset(map->map, 0, 5 + 1);
    if (map->map == NULL)
    {
        close(fd);
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {

        duplicate_characters(line, &rules);
        map->map[numlines] = (char *)malloc((ft_gnl_strlen(line) + 1) * sizeof(char));
        if (!map->map[numlines])
        {
            free(line);
            free_map(map, numlines);
            close(fd);
            return (1);
        }
        ft_strlcpy(map->map[numlines], line, ft_gnl_strlen(line) + 1);
        free(line);
        printf("map[%d]:%s\n", numlines, map->map[numlines]);
        // printf("%d %ld\n", prev_lenline, ft_gnl_strlen(map->map[numlines]));
        if (numlines > 0 && is_rectangular(prev_lenline, ft_gnl_strlen(map->map[numlines])) == 1)
        {
            printf("here\n");
            free_map(map, numlines);
            close(fd);

            return (1);
        }
        prev_lenline = ft_gnl_strlen(map->map[numlines]);
        map->x = prev_lenline;
        numlines++;
        map->y = numlines;
    }

    close(fd);
    if (numlines == 1 || rules > 3)
    {
        free_map(map, numlines);
        return (1);
    }
    return (0);
}
