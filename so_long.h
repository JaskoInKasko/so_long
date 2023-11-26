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
	char	*filename;
	char	*line;
	char	*line_cpy;
	int		columns;
	int		rows;
	char	**fullmap;
}	t_map_data;
int	ft_valid_map(t_map_data *map);

#endif
