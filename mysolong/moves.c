#include "so_long.h"

void move_vert(t_data *data, int y)
{
    // update current player pos to bg
    mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_floor, data->player_x * 33, data->player_y * 33);
    // update next pos pressed
    data->player_y = data->player_y + y;
    mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_player, data->player_x * 33, data->player_y * 33);
    mlx_do_sync(data->mlx_conn);
}

void move_horiz(t_data *data, int x)
{
    // update current player pos to bg
    mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_floor, data->player_x * 33, data->player_y * 33);
    // update next pos pressed
    data->player_x = data->player_x + x;
    mlx_put_image_to_window(data->mlx_conn, data->mlx_win, data->img.img_player, data->player_x * 33, data->player_y * 33);
    mlx_do_sync(data->mlx_conn);
}
