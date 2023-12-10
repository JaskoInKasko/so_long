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

void	ft_mlx_init(t_game *game, t_map_data *map)
{
	game->mlx = mlx_init();
	if(!game->mlx)
		return (NULL);
	game->mlx_win = mlx_new_window(game->mlx, map->columns * PXL, map->rows * PXL, "2D Game");
	if(!game->mlx_win)
		return (NULL);
}

void	ft_get_image(t_game *game, t_image *image)
{
	int	p;

	p = PXL;
	image->player_up = mlx_xpm_file_to_image(game->mlx, "images/Gojo_up.xpm", &p, &p);
	image->player_up2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_up2.xpm", &p, &p);
	image->player_down = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right.xpm", &p, &p);
	image->player_down2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right2.xpm", &p, &p);
	image->player_left = mlx_xpm_file_to_image(game->mlx, "images/Gojo_left.xpm", &p, &p);
	image->player_left2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_left2.xpm", &p, &p);
	image->player_right = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right.xpm", &p, &p);
	image->player_right2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right2.xpm", &p, &p);
	image->coin = mlx_xpm_file_to_image(game->mlx, "images/Gojo_Collectible.xpm", &p, &p);
	image->exit_open = mlx_xpm_file_to_image(game->mlx, "images/exit_open.xpm", &p, &p);
	image->exit_close = mlx_xpm_file_to_image(game->mlx, "images/exit_close.xpm", &p, &p);
	image->wall = mlx_xpm_file_to_image(game->mlx, "images/Snowy_Wall.xpm", &p, &p);
	image->floor = mlx_xpm_file_to_image(game->mlx, "images/Snowy_floor.xpm", &p, &p);
	ft_check_image(game, image);
}

void	ft_image_type(t_game *game, t_map_data *map, t_image *image)
{
	char	current;

	current = map->fullmap[map->x][map->y];
	if (current == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->floor, map->x * PXL, map->y * PXL);
	else if (current == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->wall, map->x * PXL, map->y * PXL);
	else if (current == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->player_down, map->x * PXL, map->y * PXL);
	else if (current == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->coin, map->x * PXL, map->y * PXL);
	else if (current == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, image->exit_close, map->x * PXL, map->y * PXL);
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
