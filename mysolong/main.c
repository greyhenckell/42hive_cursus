#include "so_long.h"
#include "libft.h"
#include "X11/keysym.h"
#include <stdlib.h>
#include <stdio.h>

int ft_exit(t_data *data)
/* will show a message in the terminal and exit the process */
{
    if (data->mlx_win)
        mlx_destroy_window(data->mlx_conn, data->mlx_win);
    mlx_destroy_display(data->mlx_conn);
    free(data->mlx_conn);
    printf("You gave up :(\n");
    printf("Is the map to hard for you?\n");
    exit(EXIT_SUCCESS);
}

void get_pos_player(t_data *data)
{
    int row = 0;
    int col = 0;
    while (row < data->map->y)
    {
        while (col < data->map->x)
        {
            if (data->map->map[row][col] == 'P')
            {
                data->player_x = col;
                data->player_y = row;
            }
            col++;
        }
        col = 0;
        row++;
    }
}

int controls_working(int key, t_data *data)
{
    printf("Press %d\n", key);
    void (*move)(t_data *, int) = NULL;
    int direction = 1;
    if (key == XK_Escape)
        ft_exit(data);
    if (key == XK_a)
    {
        printf("move up: %d %d \n", data->player_x, data->player_y);
        direction *= -1;
        move = move_horiz;
    }
    if (key == XK_d)
    {
        printf("move up: %d %d \n", data->player_x, data->player_y);
        move = move_horiz;
    }

    if (key == XK_w)
    {
        printf("move up: %d %d \n", data->player_x, data->player_y);
        direction = -1;
        move = move_vert;
    }
    if (key == XK_s)
    {
        printf("move up: %d %d \n", data->player_x, data->player_y);
        move = move_vert;
    }
    if (move)
        move(data, direction);
    return 0;
}

void start_game(t_data *data)
{
    if (!data)
        return;

    data->mlx_conn = mlx_init();
    if (!data->mlx_conn)
    {
        printf("Error: Failed to initialize mlx\n");
        return;
    }

    data->mlx_win = mlx_new_window(data->mlx_conn, data->map->x * 40, data->map->y * 40, "SoLong");
    if (!data->mlx_win)
    {
        mlx_destroy_display(data->mlx_conn);
        free(data->mlx_conn);
        printf("Error: Failed to create a window\n");
        return;
    }
    game_setup(data->map, &(data->img), data->mlx_conn, data->mlx_win);
    get_pos_player(data);
    mlx_key_hook(data->mlx_win, controls_working, data);
    mlx_hook(data->mlx_win, 17, 1L << 2, ft_exit, data);
    mlx_loop(data->mlx_conn);
}

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        t_data data;
        t_map *map;

        data = (t_data){0};
        int state = 0;
        map = malloc(sizeof(t_map));
        if (map == NULL)
            return (1);
        data.map = map;
        state = read_map(argv[1], data.map);
        if (state == 1)
        {
            free(data.map);
            printf("Error: not valid map, %s\n", argv[1]);
            return (1);
        }
        printf("W:%d H:%d\n", data.map->x, data.map->y);
        start_game(&data);
        free(map);
    }
    else
    {
        printf("File Error: provide .ber map\n");
        return (1);
    }

    return (0);
}