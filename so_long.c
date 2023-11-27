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

void    ft_map_init(t_map_data *map, char *argv[])
{
    map->filename = argv[1];
    map->columns = 0;
    map->rows = 0;
}

int main(int argc, char *argv[])
{
    t_map_data  map;
    int x = 0;

    if(argc == 2)
    {
        ft_map_init(&map, argv);
        ft_valid_map(&map);
        while(map.fullmap[x] != NULL)
        {
            ft_printf("%s", map.fullmap[x]);
            x++;
        }
        ft_free_map(&map);
    }
    //else
    //    ft_map_error(10);
    return (0);
}
