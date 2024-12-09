#include "mlx_linux/mlx.h"

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}
int main()
{
    void *mlx;
    void *mlx_win;
    t_data inst_img;

    mlx = mlx_init();

    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    inst_img.img = mlx_new_image(mlx, 1920, 1080);
    inst_img.addr = mlx_get_data_addr(inst_img.img, &inst_img.bits_per_pixel, &inst_img.line_length,
                                      &inst_img.endian);
    my_mlx_pixel_put(&inst_img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, inst_img.img, 0, 0);
    mlx_loop(mlx);
}