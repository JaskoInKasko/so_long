#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <X11/X.h>
# include "../included_functions/libft/libft.h"
# include "../included_functions/ft_printf/ft_printf.h"
# include "../included_functions/get_next_line/get_next_line.h"

//		WINDOW MANAGEMENT
# define PXL 100

//		KEYCODE
# define ESC 65307
# define Key_UP 119
# define Key_DOWN 115
# define Key_LEFT 97
# define Key_RIGHT 100

typedef struct s_image
{
	void	*player_up;
	void	*player_up2;
	void	*player_down;
	void	*player_down2;
	void	*player_left;
	void	*player_left2;
	void	*player_right;
	void	*player_right2;
	void	*player_still;
	void	*player_still2;
	void	*player_still3;
	void	*player_still4;
	void	*coin;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*floor;
	void	*victory;
}	t_image;

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
	int		flagC2;
	char	**fullmap;
	char	**fullmap_cpy;
}	t_map_data;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int	player_x;
	int	player_y;
	int	coin_x;
	int	coin_y;
	int	exit_x;
	int	exit_y;
	int	pl_up;
	int	pl_down;
	int	pl_left;
	int	pl_right;
	int	moves;
	int	win;
	t_map_data *map;
	t_image image;
}	t_game;

//		MAP
int		ft_valid_map(t_game *game, t_map_data *map);

//		MAP_UTILS
void	ft_free_map(t_map_data *map);
void	ft_map_errors(t_map_data *map, int n);
void	ft_short_function(t_map_data *map);
void	ft_get_positions(t_game *game, t_map_data *map);
void	ft_map_valid_path(t_game *game, t_map_data *map);

//		GAME
void	ft_mlx_init(t_game *game, t_map_data *map);
void	ft_get_image(t_game *game);
void	ft_image_type(t_game *game, t_map_data *map);
void	ft_render_map(t_game *game, t_map_data *map);
void	ft_close(t_game *game);

//		GAME_UTILS
int		player_animation(t_game *game);
void    ft_outcome(t_game *game);
void    ft_free_all(t_game *game);
void	ft_victory(t_game *game);

//		EVENTS
int		key_hook(int keycode, t_game *game);

#endif
