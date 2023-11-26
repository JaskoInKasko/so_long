#include "so_long.h"

void    ft_map_init(t_map_data *map, char *argv)
{
    map->filename = argv;
    map->line = "";
    map->line_cpy = "";
    map->columns = 0;
    map->rows = 0;
}

int main(int argc, char *argv[])
{
    t_map_data  map;
    int x = 0;

    if(argc == 2)
    {
        ft_map_init(&map, "maps/map_1.ber");
        ft_valid_map(&map);
        while(map.fullmap[x])
        {
            ft_printf("%s", map.fullmap[x]);
            x++;
        }
    }
    //else
    //    ft_map_error(10);
    return (0);
}