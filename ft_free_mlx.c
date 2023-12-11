#include "so_long.h"
void    ft_free_all(t_game *game, t_map_data *map, t_image *image)
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
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
    ft_free_map(map);
}