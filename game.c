/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:50:57 by jsakanov          #+#    #+#             */
/*   Updated: 2023/12/06 15:40:24 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "2D Game");
}

void	ft_get_image(t_game *game, t_image *image)
{
	image->player_up = mlx_xpm_file_to_image(game->mlx, "images/Snowman.xpm", 14, 16);
	image->player_up2 = mlx_xpm_file_to_image();
	image->player_down = mlx_xpm_file_to_image();
	image->player_down2 = mlx_xpm_file_to_image();
	image->player_left = mlx_xpm_file_to_image();
	image->player_left2 = mlx_xpm_file_to_image();
	image->player_right = mlx_xpm_file_to_image();
	image->player_right2 = mlx_xpm_file_to_image();
	image->coin = mlx_xpm_file_to_image();
	image->exit_open = mlx_xpm_file_to_image();
	image->exit_close = mlx_xpm_file_to_image();
	image->wall = mlx_xpm_file_to_image();
	image->floor = mlx_xpm_file_to_image();
}

void	ft_image_type(t_game *game, t_map_data *map, t_image *image)
{
	char	*current;

	current = map->fullmap[map->x][map->y];
	if (current == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->floor, x * PXL, y * PXL);
	if (current == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->wall, x * PXL, y * PXL);
	if (current == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->player_down, x * PXL, y * PXL);
	if (current == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->coin, x * PXL, y * PXL);
	if (current == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->exit_close, x * PXL, y * PXL);
}

void	ft_render_map(t_game *game, t_map_data *map, t_image *image)
{
	map->x = 0;
	map->y = 0;
	
	while(map->fullmap[map->x] != NULL)
	{
		while(map->y < map->columns)
		{
			ft_image_type(game, map, image);
			map->y++;
		}
		map->y = 0;
		map->x++;
	}
}
