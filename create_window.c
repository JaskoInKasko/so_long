#include <mlx.h>

typedef struct	s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
	int		a;

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1080, "2D Game");
    img.img = mlx_new_image(mlx, 1920, 1080);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*a = 0;
	while (a < 100)
	{
    	my_mlx_pixel_put(&img, a, 30, 0x00FF0000);
		a++;
	}*/
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_loop(mlx);
}
