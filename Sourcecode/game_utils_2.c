/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:30:43 by jsakanov          #+#    #+#             */
/*   Updated: 2023/12/19 15:30:46 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_victory(t_game *game)
{
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

int	ft_close(t_game *game)
{
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
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
