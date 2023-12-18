/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:13:05 by jsakanov          #+#    #+#             */
/*   Updated: 2023/12/18 21:27:48 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_no_map_alloc(t_map_data *map, int n)
{
	if (n == 20)
		ft_printf("Error\nEmpty line in map!\n");
	if (n == 25)
		ft_printf("Error\nMap extension needs to be of type .ber!\n");
	if (n == 30)
		ft_printf("Error\nFile couldn't be opened.");
	if (n == 30)
		ft_printf(" Please check if file exists!\n");
	if (n == 35)
		ft_printf("Error\nEmpty file or passed argument is a directory!\n");
	if (n == 40)
		ft_printf("Error\nft_strjoin_free function failed!\n");
	if (n == 45)
		ft_printf("Error\nft_split function failed!\n");
	if (n == 20 || n == 40)
		free(map->line);
	if (n == 20 || n == 35 || n == 40)
		close(map->fd);
	if (n != 25)
		free(map->line_cpy);
	exit(EXIT_FAILURE);
}

void	ft_map_errors(t_map_data *map, int n)
{
	if (n == 5)
		ft_printf("Error\nLines needs to be of equal size!\n");
	else if (n == 10)
	{
		ft_printf("Error\nInvalid character/s in the map!");
		ft_printf(" Only valid characters: 0 1 C E P!\n");
	}
	else if (n == 15)
		ft_printf("Error\nInvalid map size!\n");
	else if (n == 50)
		ft_printf("Error\nMap not surrounded by walls!\n");
	else if (n == 55)
		ft_printf("Error\nWrong amount of objects in map!\n");
	else if (n == 60)
		ft_printf("Error\nNo valid path!\n");
	else if (n)
		ft_no_map_alloc(map, n);
	ft_free_map(map);
	exit(EXIT_FAILURE);
}

void	ft_get_positions(t_game *game, t_map_data *map)
{
	if (map->fullmap[map->x][map->y] == 'P')
	{
		game->player_x = map->x;
		game->player_y = map->y;
		map->flagp++;
	}
	if (map->fullmap[map->x][map->y] == 'E')
	{
		game->exit_x = map->x;
		game->exit_y = map->y;
		map->flage++;
	}
	if (map->fullmap[map->x][map->y] == 'C')
	{
		map->flagc++;
		map->flagc2 = map->flagc;
	}
}

void	ft_short_function(t_map_data *map)
{
	if (map->line_cpy[ft_strlen(map->line_cpy) - 1] == '\n')
		ft_map_errors(map, 20);
	map->fullmap = ft_split(map->line_cpy, '\n');
	map->fullmap_cpy = ft_split(map->line_cpy, '\n');
	if (!map->fullmap || !map->fullmap_cpy)
		ft_map_errors(map, 45);
}

void	ft_free_map(t_map_data *map)
{
	int	x;

	x = 0;
	while (map->fullmap[x] != NULL || map->fullmap_cpy[x] != NULL)
	{
		free(map->fullmap[x]);
		free(map->fullmap_cpy[x]);
		x++;
	}
	free(map->fullmap);
	free(map->fullmap_cpy);
}
