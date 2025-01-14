#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "libft.h"

#define WIDTH 1080
#define HEIGHT 920

#define ESC 65307

typedef struct s_map
{
    char **map;
    void *object;
    int x;
    int y;

} t_map;

typedef struct s_img
{
    void *img_floor;
    void *img_wall;
    void *img_collectible;
    void *img_exit;
    void *img_player;
    char *img_buffer;
    int bpp; // bits per pixel
    int endian;
    int linelen;
} t_img;

typedef struct s_data
{
    void *mlx_conn;
    void *mlx_win;
    t_img img;
    t_map *map;
    int player_x;
    int player_y;
} t_data;

int read_map(char *src, t_map *map);
void game_setup(t_map *data, t_img *img, void *conn, void *win);

void move_vert(t_data *data, int y);
void move_horiz(t_data *data, int x);

#endif