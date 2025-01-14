#include "so_long.h"
#include <stdio.h>

void load_textures(t_img *img, void *conn)
{
    if (!img)
        return;
    int x;
    int y;
    img->img_floor = mlx_xpm_file_to_image(conn, "./textures/floor.xpm", &x, &y);
    img->img_wall = mlx_xpm_file_to_image(conn, "./textures/wall.xpm", &x, &y);
    img->img_player = mlx_xpm_file_to_image(conn, "./textures/player.xpm", &x, &y);
    img->img_exit = mlx_xpm_file_to_image(conn, "./textures/exit.xpm", &x, &y);
    img->img_collectible = mlx_xpm_file_to_image(conn, "./textures/collectible.xpm", &x, &y);
}

void game_setup(t_map *map, t_img *img, void *conn, void *win)
{
    if (map == NULL)
        return;

    load_textures(img, conn);
    if (!img->img_exit || !img->img_floor)
        printf("Error load image\n");

    int row = 0;
    int item = 0;
    while (row < map->y)
    {
        while (map->map[row][item] != '\0')
        {
            // printf(":%c", map->map[row][item]);
            if (map->map[row][item] == '0')
                mlx_put_image_to_window(conn, win, img->img_floor, item * 33, row * 33);
            if (map->map[row][item] == '1')
                mlx_put_image_to_window(conn, win, img->img_wall, item * 33, row * 33);
            if (map->map[row][item] == 'C')
                mlx_put_image_to_window(conn, win, img->img_collectible, item * 33, row * 33);
            if (map->map[row][item] == 'P')
                mlx_put_image_to_window(conn, win, img->img_player, item * 33, row * 33);
            if (map->map[row][item] == 'E')
                mlx_put_image_to_window(conn, win, img->img_exit, item * 33, row * 33);

            item++;
        }
        item = 0;
        row++;
    }
}
