/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:12:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/27 17:12:53 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_game_init(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->coin_x = 0;
	game->coin_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
}

void	ft_map_init(t_map_data *map, char *argv[])
{
	map->filename = argv[1];
	map->columns = 0;
	map->rows = 0;
	map->x = 1;
	map->y = 0;
	map->flagP = 0;
    map->flagE = 0;
	map->flagC = 0;
}

int	main(int argc, char *argv[])
{
	t_map_data	map;
	t_game		game;
	t_image		image;

	if (argc == 2)
	{
		ft_map_init(&map, argv);
		ft_valid_map(&game, &map);
		ft_mlx_init(&game, &map);
		ft_get_image(&game, &image);
		ft_render_map(&game, &map, &image);
		mlx_loop(game.mlx);
	}
	else
		ft_printf("Error\nWrong number of arguments! Expected: 2!\n");
	return (0);
}
