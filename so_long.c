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
	game->pl_up = 1;
	game->pl_down = 1;
	game->pl_left = 1;
	game->pl_right = 1;
	game->moves = 0;
	game->win = 0;
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
	map->flagC2 = 0;
}

int	main(int argc, char *argv[])
{
	t_map_data	map;
	t_game		game;

	if (argc == 2)
	{
		ft_game_init(&game);
		ft_map_init(&map, argv);
		ft_valid_map(&game, &map);
		ft_mlx_init(&game, &map);
		ft_get_image(&game);
		ft_render_map(&game, &map);
		mlx_key_hook(game.mlx_win, key_hook, &game);
		mlx_loop_hook(game.mlx, player_animation, &game);
		mlx_loop(game.mlx);
		ft_free_all(&game);
	}
	else
		ft_printf("Error\nWrong number of arguments! Expected: 2!\n");
	return (0);
}
