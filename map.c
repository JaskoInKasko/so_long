/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:33 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/24 17:24:04 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/*int	ft_map_valid_char(char *line, int fd)
{
	int		i;
	char	c;

	i = 0;
	while(line[i] != '\0')
	{
		c = line[i];
		if(!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
		{
			ft_map_error(5);
			free(line);
			close(fd);
			return (0);
		}
		i++;
	}
	return (1);
}*/

int	ft_fill_fullmap(t_map_data *map)
{
	int		fd;

	fd = open(map->filename, O_RDONLY);
	if(fd == -1)
		return (0);
	while(1)
	{
		map->line = get_next_line(fd);
		if(!map->line)
			break ;
		map->line_cpy = ft_strjoin(map->line_cpy, map->line);
		if(!map->line_cpy)
			return(close(fd), free(map->line), 0);
		map->rows++;
		free(map->line);
	}
	close (fd);
	map->fullmap = ft_split(map->line_cpy, '\n');
	if(!map->fullmap)
		free(map->fullmap);
	return (1);
}

int	ft_valid_map(t_map_data *map)
{
	if((ft_fill_fullmap(map)) == 0)
		return (0);
	return (1);
}