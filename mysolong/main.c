#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

int ft_exit(t_data *data)
/* will show a message in the terminal and exit the process */
{
    if (data->mlx_win)
        mlx_destroy_window(data->mlx_conn, data->mlx_win);
    free(data->mlx_win);
    printf("You gave up :(\n");
    printf("Is the map to hard for you?\n");
    exit(EXIT_SUCCESS);
}

int controls_working(int key, t_data *data)
{
    printf("Press %d\n", key);
    if (key == 65307)
        ft_exit(data);
    return 0;
}

void start_game(t_map *map)
{
    if (!map)
        return;
    t_data setmlx;
    setmlx.mlx_conn = mlx_init();
    if (!setmlx.mlx_conn)
    {
        printf("Error: Failed to initialize mlx\n");
        return;
    }

    setmlx.mlx_win = mlx_new_window(setmlx.mlx_conn, map->x * 40, map->y * 40, "SoLong");
    if (!setmlx.mlx_win)
    {
        mlx_destroy_display(setmlx.mlx_conn);
        free(setmlx.mlx_conn);
        printf("Error: Failed to create a window\n");
        return;
    }
    game_setup(&setmlx, map);
    mlx_key_hook(setmlx.mlx_win, controls_working, &setmlx);
    mlx_hook(setmlx.mlx_conn, 17, 1L << 2, ft_exit, &setmlx);
    mlx_loop(setmlx.mlx_conn);
}

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        t_map *map;
        int state = 0;
        map = malloc(sizeof(t_map));
        if (map == NULL)
            return (1);
        state = read_map(argv[1], map);
        if (state == 1)
        {
            free(map);
            printf("Error: not valid map, %s\n", argv[1]);
            return (1);
        }
        printf("W:%d H:%d\n", map->x, map->y);
        start_game(map);
    }
    else
    {
        printf("File Error: provide .ber map\n");
        return (1);
    }

    return (0);
}