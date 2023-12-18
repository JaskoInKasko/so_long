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

void	ft_coin_animation(t_game *game, int *frames_coin)
{
	while (game->map->fullmap[game->map->x] != NULL)
	{
		while (game->map->y < game->map->columns)
		{
			if (game->map->flagc != 0
				&& game->map->fullmap[game->map->x][game->map->y] == 'C')
			{
				if (*frames_coin == 15000)
					mlx_put_image_to_window(game->mlx, game->mlx_win,
						game->image.coin,
						game->map->y * PXL, game->map->x * PXL);
				if (*frames_coin == 30000)
					mlx_put_image_to_window(game->mlx, game->mlx_win,
						game->image.coin2,
						game->map->y * PXL, game->map->x * PXL);
				if (*frames_coin == 45000)
					mlx_put_image_to_window(game->mlx, game->mlx_win,
						game->image.coin3,
						game->map->y * PXL, game->map->x * PXL);
				if (*frames_coin == 45001)
					*frames_coin = 0;
			}
			game->map->y++;
		}
		game->map->y = 0;
		game->map->x++;
	}
	*frames_coin += 1;
}

int	player_animation(t_game *game)
{
	static int	frames;
	static int	frames_coin;

	if (game->win != 1)
	{
		if (frames == 30000)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->image.player_still,
				game->player_y * PXL, game->player_x * PXL);
		if (frames == 60000)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->image.player_still2,
				game->player_y * PXL, game->player_x * PXL);
		if (frames == 90000)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->image.player_still3,
				game->player_y * PXL, game->player_x * PXL);
		if (frames == 120000)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->image.player_still4,
				game->player_y * PXL, game->player_x * PXL);
		frames += 1;
		if (frames == 120001)
			frames = 0;
	}
	game->map->x = 0;
	ft_coin_animation(game, &frames_coin);
	return (0);
}

void	ft_victory(t_game *game)
{
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

void	ft_outcome(t_game *game)
{
	if (game->map->fullmap[game->player_x][game->player_y] == 'C')
	{
		game->map->fullmap[game->player_x][game->player_y] = '0';
		game->map->flagc--;
	}
	if (game->map->flagc != 0
		&& game->map->fullmap[game->player_x][game->player_y] != 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.exit_close,
			game->exit_y * PXL, game->exit_x * PXL);
	else if (game->map->flagc == 0
		&& game->map->fullmap[game->player_x][game->player_y] != 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->image.exit_open,
			game->exit_y * PXL, game->exit_x * PXL);
	if (game->map->flagc == 0
		&& game->map->fullmap[game->player_x][game->player_y] == 'E')
	{
		game->win = 1;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.victory,
			((game->map->columns * PXL) - (PXL * 2)) / 2,
			((game->map->rows * PXL) - (PXL * 3)) / 2);
	}
}

void	ft_free_all(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.wall);
	mlx_destroy_image(game->mlx, game->image.floor);
	mlx_destroy_image(game->mlx, game->image.coin);
	mlx_destroy_image(game->mlx, game->image.coin2);
	mlx_destroy_image(game->mlx, game->image.coin3);
	mlx_destroy_image(game->mlx, game->image.exit_open);
	mlx_destroy_image(game->mlx, game->image.exit_close);
	mlx_destroy_image(game->mlx, game->image.player_up);
	mlx_destroy_image(game->mlx, game->image.player_up2);
	mlx_destroy_image(game->mlx, game->image.player_down);
	mlx_destroy_image(game->mlx, game->image.player_down2);
	mlx_destroy_image(game->mlx, game->image.player_left);
	mlx_destroy_image(game->mlx, game->image.player_left2);
	mlx_destroy_image(game->mlx, game->image.player_right);
	mlx_destroy_image(game->mlx, game->image.player_right2);
	mlx_destroy_image(game->mlx, game->image.player_still);
	mlx_destroy_image(game->mlx, game->image.player_still2);
	mlx_destroy_image(game->mlx, game->image.player_still3);
	mlx_destroy_image(game->mlx, game->image.player_still4);
	mlx_destroy_image(game->mlx, game->image.victory);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_map(game->map);
}
