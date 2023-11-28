/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:33 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/27 14:56:22 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_map_extension(t_map_data *map)
{
	char	*file_extension;
	char	*extension;

	extension = ".ber";
	file_extension = ft_strrchr(map->filename, '.');
	if (!file_extension)
		ft_map_errors(map, 25);
	if ((ft_strcmp(file_extension, extension)) != 0)
		ft_map_errors(map, 25);
	return (1);
}

int	ft_map_lines_len_and_char(t_map_data *map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	map->columns = ft_strlen(map->fullmap[x]);
	while (map->fullmap[x + 1] != NULL)
	{
		y = 0;
		if ((ft_strlen(map->fullmap[x])) != ft_strlen(map->fullmap[x + 1]))
			ft_map_errors(map, 5);
		while (y < map->columns)
		{
			c = map->fullmap[x][y];
			if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
				ft_map_errors(map, 10);
			y++;
		}
		x++;
	}
	if (x < 2)
		ft_map_errors(map, 15);
	return (1);
}

int	ft_map_is_wall_and_no_dup(t_map_data *map)
{
	while (map->fullmap[map->x] != NULL)
	{
		while (map->y < map->columns)
		{
			if (map->fullmap[map->x][map->y] == 'P')
				map->flagP++;
			if (map->fullmap[map->x][map->y] == 'E')
				map->flagE++;
			if (map->fullmap[0][map->y] != '1' ||
				map->fullmap[map->rows - 1][map->y] != '1')
				ft_map_errors(map, 50);
			map->y++;
		}
		if (map->fullmap[map->x][0] != '1' ||
			map->fullmap[map->x][map->columns - 1] != '1')
			ft_map_errors(map, 50);
		map->x++;
		map->y = 0;
	}
	if (map->flagP != 1 || map->flagE != 1)
		ft_map_errors(map, 55);
	return (1);
}

int	ft_fill_fullmap(t_map_data *map)
{
	map->line_cpy = ft_strdup("");
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
		ft_map_errors(map, 30);
	while (1)
	{
		map->line = get_next_line(map->fd);
		if (!map->line && map->rows == 0)
			ft_map_errors(map, 35);
		if (!map->line)
			break ;
		if (map->line[0] == '\n')
			ft_map_errors(map, 20);
		map->line_cpy = ft_strjoin_free(map->line_cpy, map->line);
		if (!map->line_cpy)
			ft_map_errors(map, 40);
		map->rows++;
		free(map->line);
	}
	close (map->fd);
	ft_short_function(map);
	free(map->line_cpy);
	return (1);
}

int	ft_valid_map(t_map_data *map)
{
	ft_map_extension(map);
	ft_fill_fullmap(map);
	ft_map_lines_len_and_char(map);
	ft_map_is_wall_and_no_dup(map);
	return (1);
}
