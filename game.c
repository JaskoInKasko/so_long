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
	{
		ft_printf("Error\nInitialization has failed!\n");
		exit(EXIT_FAILURE);
	}
	game->mlx_win = mlx_new_window(game->mlx, map->columns * PXL, map->rows * PXL, "2D Game");
}

void	ft_get_image(t_game *game)
{
	int	p;

	p = PXL;
	game->image.player_up = mlx_xpm_file_to_image(game->mlx, "images/Gojo_up.xpm", &p, &p);
	game->image.player_up2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_up2.xpm", &p, &p);
	game->image.player_down = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right.xpm", &p, &p);
	game->image.player_down2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right2.xpm", &p, &p);
	game->image.player_left = mlx_xpm_file_to_image(game->mlx, "images/Gojo_left.xpm", &p, &p);
	game->image.player_left2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_left2.xpm", &p, &p);
	game->image.player_right = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right.xpm", &p, &p);
	game->image.player_right2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_right2.xpm", &p, &p);
	game->image.coin = mlx_xpm_file_to_image(game->mlx, "images/Collectible.xpm", &p, &p);
	game->image.exit_open = mlx_xpm_file_to_image(game->mlx, "images/exit_open.xpm", &p, &p);
	game->image.exit_close = mlx_xpm_file_to_image(game->mlx, "images/exit_close.xpm", &p, &p);
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "images/Snowy_Wall.xpm", &p, &p);
	game->image.floor = mlx_xpm_file_to_image(game->mlx, "images/Snowy_Floor.xpm", &p, &p);
	game->image.player_still = mlx_xpm_file_to_image(game->mlx, "images/Gojo_still.xpm", &p, &p);
	game->image.player_still2 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_still2.xpm", &p, &p);
	game->image.player_still3 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_still3.xpm", &p, &p);
	game->image.player_still4 = mlx_xpm_file_to_image(game->mlx, "images/Gojo_still4.xpm", &p, &p);
	game->image.victory = mlx_xpm_file_to_image(game->mlx, "images/victory.xpm", &p, &p);
}

void	ft_image_type(t_game *game, t_map_data *map)
{
	char	current;

	current = map->fullmap[map->x][map->y];
	if (current == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.floor, map->y * PXL, map->x * PXL);
	else if (current == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.wall, map->y * PXL, map->x * PXL);
	else if (current == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_down, map->y * PXL, map->x * PXL);
	else if (current == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.coin, map->y * PXL, map->x * PXL);
	else if (current == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.exit_close, map->y * PXL, map->x * PXL);
}

void	ft_close(t_game *game)
{
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

void	ft_render_map(t_game *game, t_map_data *map)
{
	map->x = 0;
	map->y = 0;
	while(map->fullmap[map->x] != NULL)
	{
		while(map->y < map->columns)
		{
			ft_image_type(game, map);
			map->y++;
		}
		map->y = 0;
		map->x++;
	}
}
