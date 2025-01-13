#include "so_long.h"
#include <stdio.h>

void load_textures(t_data *data)
{
    if (!data)
        return;
    int x;
    int y;
    data->img.img_floor = mlx_xpm_file_to_image(data->mlx_conn, "./textures/floor.xpm", &x, &y);
    data->img.img_wall = mlx_xpm_file_to_image(data->mlx_conn, "./textures/wall.xpm", &x, &y);
    data->img.img_player = mlx_xpm_file_to_image(data->mlx_conn, "./textures/player.xpm", &x, &y);
    data->img.img_exit = mlx_xpm_file_to_image(data->mlx_conn, "./textures/exit.xpm", &x, &y);
    data->img.img_collectible = mlx_xpm_file_to_image(data->mlx_conn, "./textures/collectible.xpm", &x, &y);
}

void game_setup(t_data *data, t_map *map)
{
    if (data == NULL || map == NULL)
        return;
    load_textures(data);
    if (!data->img.img_exit || !data->img.img_floor)
        printf("Error load image\n");

    int row = 0;
    int item = 0;
    while (row < map->y)
    {
        while (map->map[row][item] != '\0')
        {
            // printf(":%c", map->map[row][item]);
            if (map->map[row][item] == '0')
                mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_floor, item * 32, row * 32);
            if (map->map[row][item] == '1')
                mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_wall, item * 32, row * 32);
            if (map->map[row][item] == 'C')
                mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_collectible, item * 32, row * 32);
            if (map->map[row][item] == 'P')
                mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_player, item * 32, row * 32);
            if (map->map[row][item] == 'E')
                mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_exit, item * 32, row * 32);

            item++;
        }
        item = 0;
        row++;
    }
}

// setmlx.img.img_ptr = mlx_new_image(setmlx.mlx_conn, WIDTH, HEIGHT);

// vars.img.linelen = WIDTH * 4;

// setmlx.img.img_buffer = mlx_get_data_addr(setmlx.img.img_ptr, &setmlx.img.bpp, &setmlx.img.linelen, &setmlx.img.endian);
//  ft_put_pixel(&setmlx.img, 10, 10, 0x00FF0000);
//  mlx_put_image_to_window(setmlx.mlx_conn, setmlx.mlx_win, setmlx.img.img_ptr, 100, 100);
// mlx_loop_hook(setmlx.mlx_conn, render_frame, &setmlx);
//  mlx_key_hook(setmlx.mlx_win, key_hook, &setmlx);
//  mlx_hook(setmlx.mlx_win, 2, 1L << 0, ft_close, &setmlx);
