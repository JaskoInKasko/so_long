CC = cc
CFLAGS = -Wall -Wextra -Werror -g
HEAD = ft_printf.h
SRC = so_long.c game.c game_utils.c map.c map_utils.c ft_game_utils_2.c\
ft_map_valid_path.c events.c ../included_functions/get_next_line/get_next_line_utils.c\
../included_functions/get_next_line/get_next_line.c\


OBJ = $(SRC:.c=.o)
NAME = so_long
FT_PRINTF = ./../included_functions/ft_printf/libftprintf.a
LIBFT = ./../included_functions/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ../included_functions/ft_printf --no-print-directory
	@$(MAKE) -C ../included_functions/libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME) -lmlx -lX11 -lXext

.PHONY: all clean fclean re included_functions

clean:
	cd ../included_functions/libft && $(MAKE) clean
	cd ../included_functions/ft_printf && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd ../included_functions/libft && $(MAKE) fclean
	cd ../included_functions/ft_printf && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all
