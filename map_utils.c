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

void    ft_no_map_alloc(t_map_data *map, int n)
{
    if(n == 20)
        ft_printf("Error\nnewline char or empty line in map!\n");
    if(n == 25)
        ft_printf("Error\nEmpty line at the end of the map!\n");
    if(n == 30)
        ft_printf("Error\nMap extension needs to be of type .ber!\n");
    if(n == 35)
        ft_printf("Error\nFile couldn't be opened. Please check if file exists!\n");
    if(n == 40)
        ft_printf("Error\nEmpty file or passed argument is a directory!\n");
    if(n == 45)
        ft_printf("Error\nft_strjoin_free function failed!\n");
    if(n == 50)
        ft_printf("Error\nft_split function failed!\n");
    if(n == 20 || n == 45)
        free(map->line);
    if(n == 20 || n == 40 || n == 45)
        close(map->fd);
    free(map->line_cpy);
    exit(EXIT_FAILURE);
}

void    ft_map_errors(t_map_data *map, int n)
{
    if(n == 5)
        ft_printf("Error\nLines needs to be of equal size!\n");
    if(n == 10)
    {
        ft_printf("Error\nInvalid character/s in the map!");
		ft_printf(" Only valid characters: 0 1 C E P\n");
    }
    if(n == 15)
        ft_printf("Error\nTo less lines\n");
    ft_no_map_alloc(map, n);
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