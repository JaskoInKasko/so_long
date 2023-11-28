#ifndef	SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include "included_functions/libft/libft.h"
# include "included_functions/ft_printf/ft_printf.h"
# include "included_functions/get_next_line/get_next_line.h"

# ifndef MAX_MAP_SIZE
#  define MAX_MAP_SIZE 500
# endif

typedef struct s_map_data
{
	int		fd;
	char	*filename;
	char	*line;
	char	*line_cpy;
	int		columns;
	int		rows;
	char	**fullmap;
}	t_map_data;

//		MAP
int		ft_valid_map(t_map_data *map);

//		MAP_UTILS
void	ft_free_map(t_map_data *map);
void	ft_map_errors(t_map_data *map, int n);

#endif
