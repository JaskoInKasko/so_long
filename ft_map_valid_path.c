/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:23:26 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/30 17:23:31 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void ft_map_traverse(t_map_data *map, int x, int y)
{
    char    current;

    map->x = x;
    map->y = y;
    current = map->fullmap_cpy[map->x][map->y];
    if(current == 'P' || current == '0')
        map->fullmap_cpy[map->x][map->y] = '1';
    else if(current == 'C')
    {
        map->flagC--;
        map->fullmap_cpy[map->x][map->y] = '1';
    }
    else if(current == 'E')
    {
        map->flagE--;
        map->fullmap_cpy[map->x][map->y] = '1';
    }
    else
        return ;
    ft_map_traverse(map, x - 1, y);
    ft_map_traverse(map, x + 1, y);
    ft_map_traverse(map, x, y - 1);
    ft_map_traverse(map, x, y + 1);
}

void ft_map_valid_path(t_game *game, t_map_data *map)
{
    ft_map_traverse(map, game->player_x, game->player_y);
    if (map->flagC != 0 || map->flagE != 0)
        ft_map_errors(map, 60);
}

