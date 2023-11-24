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

int	ft_valid_char(const char c)
{
	if(!(c == '0' && c == '1' && c == 'C' && c == 'E' && c == 'P'))
		return (0);
	return (1);
}

int	ft_map_is_valid(char *line, int fd)
{
	int	i;

	i = 0;
	while(line[i] != '\0')
	{
		if(ft_valid_char(line[i]) == 1)
		{
			ft_printf("Error\nInvalid character/s in the map!");
			ft_printf(" Only valid characters: 0 1 C E P\n");
			free(line);
			close(fd);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_open_read_map(const char	*map)
{
	char	*line;
	char	buffer[MAX_MAP_SIZE][MAX_MAP_SIZE];
	int		fd;
	int		rows;
	int		columns;
	int		i;

	rows = 0;
	columns = 0;
	fd = open(map, O_RDONLY);
	if(fd == -1)
		return (0);
	while(1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			break ;
		if(ft_map_is_valid(line, fd) == 0)
			return (0);
		i = 0;
		while(line[i] != '\0')
		{
			buffer[rows][columns] = line[i];
			i++;
			columns++;
		}
		columns = 0;
		rows++;
		free(line);
	}
	close (fd);
	return (1);
}

int	main(void)
{
	char	str[30] = "maps/map_1.ber";
	ft_open_read_map(str);
	return (0);
}
