#include "so_long.h"
#include <stdio.h>
void    ft_move_up(t_game *game)
{
    if(game->map->fullmap[game->player_x - 1][game->player_y] != '1')
    {
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.floor,
            game->player_y * PXL, game->player_x * PXL);
        game->player_x--;
        if(game->pl_up % 2 != 0)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_up,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_up++;
        }
        else
        {   
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_up2,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_up++;
        }
    }
}

void    ft_move_down(t_game *game)
{
    if(game->map->fullmap[game->player_x + 1][game->player_y] != '1')
    {
        
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.floor,
            game->player_y * PXL, game->player_x * PXL);
        game->player_x++;
        if(game->pl_down % 2 != 0)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_down,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_down++;
        }
        else
        {   mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_down2,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_down++;
        }
    }
}

void    ft_move_left(t_game *game)
{
    if(game->map->fullmap[game->player_x][game->player_y - 1] != '1')
    {
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.floor,
            game->player_y * PXL, game->player_x * PXL);
        game->player_y--;
        if(game->pl_left % 2 != 0)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_left,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_left++;
        }
        else
        {   
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_left2,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_left++;
        }
    }
}

void    ft_move_right(t_game *game)
{
    if(game->map->fullmap[game->player_x][game->player_y + 1] != '1')
    {
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.floor,
            game->player_y * PXL, game->player_x * PXL);
        game->player_y++;
        if(game->pl_right % 2 != 0)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_right,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_right++;
        }
        else
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player_right2,
                game->player_y * PXL, game->player_x * PXL);
            game->pl_right++;
        }
    }
}

int key_hook(int keycode, t_game *game)
{
    //if (keycode == ESC)
    //    return (ft_close(game));
    if (keycode == Key_UP)
        ft_move_up(game);
    else if (keycode == Key_DOWN)
        ft_move_down(game);
    else if (keycode == Key_LEFT)
        ft_move_left(game);
    else if (keycode == Key_RIGHT)
        ft_move_right(game);
    return (0);
}
