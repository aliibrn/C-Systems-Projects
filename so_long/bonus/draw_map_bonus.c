/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:39:46 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/16 19:25:30 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	draw_player(t_game *game, char p)
{
	if (p == 'u')
		mlx_put_image_to_window(game->mlx, game->win, game->txt.t_player[0],
			48 * game->map.player_pos.x, 48 * game->map.player_pos.y);
	else if (p == 'l')
		mlx_put_image_to_window(game->mlx, game->win, game->txt.t_player[1],
			48 * game->map.player_pos.x, 48 * game->map.player_pos.y);
	else if (p == 'r')
		mlx_put_image_to_window(game->mlx, game->win, game->txt.t_player[2],
			48 * game->map.player_pos.x, 48 * game->map.player_pos.y);
	else if (p == 'd')
		mlx_put_image_to_window(game->mlx, game->win, game->txt.t_player[3],
			48 * game->map.player_pos.x, 48 * game->map.player_pos.y);
}

static void	draw_wall(t_game *game, int x, int y)
{
	if (y == 0 && x != 0 && x != game->map.x - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.wall_up, x * 48, y * 48);
	else if (x == 0 && y != 0 && y != game->map.y - 1)
		mlx_put_image_to_window(game->mlx,
			game->win, game->txt.wall_gauche, x * 48, y * 48);
	else if (y + 1 == game->map.y && x != 0 && x != game->map.x - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.wall_down, x * 48, y * 48);
	else if (x + 1 == game->map.x && y != game->map.y - 1 && y != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.wall_droit, x * 48, y * 48);
	else if ((x == 0 && y == 0) || (y == 0 && x == game->map.x - 1)
		|| (x == 0 && y == game->map.y - 1)
		|| (x == game->map.x - 1 && y == game->map.y - 1))
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.qunt, x * 48, y * 48);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.otherr, x * 48, y * 48);
}

static void	draw_exit_collec_empty(t_game *game, char index, int x, int y)
{
	if (index == 'x')
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.t_exit, x * 48, y * 48);
	if (index == 'e')
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.t_empty, x * 48, y * 48);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->map.map[y][x] == WALL)
				draw_wall(game, x, y);
			if (game->map.map[y][x] == EMPTY)
				draw_exit_collec_empty(game, 'e', x, y);
			if (game->map.map[y][x] == PLAYER)
				draw_player(game, 'u');
			if (game->map.map[y][x] == EXIT)
				draw_exit_collec_empty(game, 'x', x, y);
			x++;
		}
		y++;
	}
}
