/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:13:05 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:11 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void ft_map_errors(t_map_data *map, int n)
{
    if(n == 5)
    {
        ft_printf("Error\nInvalid character/s in the map!");
		ft_printf(" Only valid characters: 0 1 C E P\n");
    }
    ft_free_map(map);
    exit(EXIT_FAILURE);
}

void    ft_free_map(t_map_data *map)
{
    int x;

    x = 0;
    while(map->fullmap[x] != NULL)
    {
        free(map->fullmap[x]);
        x++;
    }
    free(map->fullmap);
}

/*int ft_map_extension(char *map)
{
    char    *file_extension;
    char    *extension;

    extension = ".ber";
    file_extension = ft_strrchr(map, '.');
    if((ft_strcmp(file_extension, extension)) != 0);
        return (0);
    return (1);
}*/
