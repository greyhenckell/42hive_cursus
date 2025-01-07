#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

#define WIDTH 600
#define HEIGHT 600

#define ESC 65307

#endif