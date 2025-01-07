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

#define WIDTH 640
#define HEIGHT 360

#define ESC 65307

int read_map(char *src);

#endif