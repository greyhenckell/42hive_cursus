#include "mlx.h"
#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars
{
    void *mlxconn_ptr;
    void *win_ptr;
} t_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int ft_exit(t_vars *data)
/* will show a message in the terminal and exit the process */
{
    mlx_destroy_window(data->mlxconn_ptr, data->win_ptr);
    printf("You gave up :(\n");
    printf("Is the map to hard for you?\n");
    exit(EXIT_SUCCESS);
}

int key_hook(int keycode, t_vars *vars)
{
    if (keycode == ESC)
        ft_exit(vars);

    printf("%d: pressed\n", keycode);
    return (0);
}

int main(void)
{
    t_vars vars;
    vars.mlxconn_ptr = mlx_init();
    if (!vars.mlxconn_ptr)
        return (1);
    vars.win_ptr = mlx_new_window(vars.mlxconn_ptr, WIDTH, HEIGHT, "hi :)");
    if (!vars.win_ptr)
    {
        mlx_destroy_display(vars.mlxconn_ptr);
        free(vars.mlxconn_ptr);
        return (1);
    }
    mlx_key_hook(vars.win_ptr, key_hook, &vars);
    mlx_loop(vars.mlxconn_ptr);
    return (0);
}