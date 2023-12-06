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

void	ft_get_image(t_image *image)
{
	image->player_up = mlx_xpm_file_to_image();
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
}
