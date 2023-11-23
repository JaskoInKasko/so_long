/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:33 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/23 17:01:05 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_check_map(const char	*line, const char c, int i)
{
	if(!(c == '0' && c == '1' && c == 'C' && c == 'E' && c == 'P'))
		return (0);
	return (1);
}

int	ft_read_map(const char	*filename)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("/maps/map_1.ber", O_RDONLY);
	while(line != NULL)
	{
		line = get_next_line(fd);
		while(line[i] != '\0')
		{
			if(ft_check_map(line, line[i], i) == 1)
			{
				ft_printf("Error: Invalid character/s in the map!\n");
				ft_printf("Only valid characters are allowed: 0 1 C E P\n");
				free(line);
				close(fd);
				return (-1);
			}
			i++;
		}
	}
}
