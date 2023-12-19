/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:42:24 by jsakanov          #+#    #+#             */
/*   Updated: 2023/12/18 21:23:58 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	coin_animation2(t_game *game, int **frames_coin)
{
	if (**frames_coin == 15000)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.coin,
			game->map->y * PXL, game->map->x * PXL);
	if (**frames_coin == 30000)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.coin2,
			game->map->y * PXL, game->map->x * PXL);
	if (**frames_coin == 45000)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.coin3,
			game->map->y * PXL, game->map->x * PXL);
	if (**frames_coin == 45001)
		**frames_coin = 0;
}

void	coin_animation(t_game *game, int *frames_coin)
{
	while (game->map->fullmap[game->map->x] != NULL)
	{
		while (game->map->y < game->map->columns)
		{
			if (game->map->flagc != 0
				&& game->map->fullmap[game->map->x][game->map->y] == 'C')
				coin_animation2(game, &*frames_coin);
			game->map->y++;
		}
		game->map->y = 0;
		game->map->x++;
	}
	*frames_coin += 1;
}

void	player_animation2(t_game *game, int *frames)
{
	if (*frames == 30000)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.player_still,
			game->player_y * PXL, game->player_x * PXL);
	if (*frames == 60000)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.player_still2,
			game->player_y * PXL, game->player_x * PXL);
	if (*frames == 90000)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.player_still3,
			game->player_y * PXL, game->player_x * PXL);
	if (*frames == 120000)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.player_still4,
			game->player_y * PXL, game->player_x * PXL);
	*frames += 1;
	if (*frames == 120001)
		*frames = 0;
}

int	player_animation(t_game *game)
{
	static int	frames;
	static int	frames_coin;

	if (game->win != 1)
		player_animation2(game, &frames);
	game->map->x = 0;
	coin_animation(game, &frames_coin);
	return (0);
}
