#ifndef SO_LONG_H
# define SO_LONG_H
# include "included_functions/libft/libft.h"
# include "included_functions/ft_printf/ft_printf.h"
# include "included_functions/get_next_line/get_next_line.h"

typedef struct s_game
{
	int	player_x;
	int	player_y;
	int	coin_x;
	int	coin_y;
	int	exit_x;
	int	exit_y;
}	t_game;


typedef struct s_map_data
{
	int		fd;
	char	*filename;
	char	*line;
	char	*line_cpy;
	int		columns;
	int		rows;
	int		x;
	int		y;
	int		flagP;
	int		flagE;
	int		flagC;
	char	**fullmap;
	char	**fullmap_cpy;
}	t_map_data;

//		MAP
int		ft_valid_map(t_game *game, t_map_data *map);

//		MAP_UTILS
void	ft_free_map(t_map_data *map);
void	ft_map_errors(t_map_data *map, int n);
void	ft_short_function(t_map_data *map);
void	ft_get_positions(t_game *game, t_map_data *map);
void	ft_map_valid_path(t_game *game, t_map_data *map);

#endif
