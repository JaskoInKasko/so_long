#include "so_long.h"
void    ft_mlx_destroy(t_game *game, t_image *image)
{
    mlx_destroy_image(game->mlx, image->wall);
    mlx_destroy_image(game->mlx, image->floor);
    mlx_destroy_image(game->mlx, image->coin);
    mlx_destroy_image(game->mlx, image->exit_open);
    mlx_destroy_image(game->mlx, image->exit_close);
    mlx_destroy_image(game->mlx, image->player_up);
    mlx_destroy_image(game->mlx, image->player_up2);
    mlx_destroy_image(game->mlx, image->player_down);
    mlx_destroy_image(game->mlx, image->player_down2);
    mlx_destroy_image(game->mlx, image->player_left);
    mlx_destroy_image(game->mlx, image->player_left2);
    mlx_destroy_image(game->mlx, image->player_right);
    mlx_destroy_image(game->mlx, image->player_right2);
    mlx_destroy_window(game->mlx_win);

}

void    ft_check_image(t_game *game, t_map_data *map, t_image *image)
{
    if(!image);
	{
		ft_free_map(map);
        ft_mlx_destroy(game, image);
		free(game->mlx);
        free(game->mlx_win)
        exit(EXIT_FAILURE);
	}
}