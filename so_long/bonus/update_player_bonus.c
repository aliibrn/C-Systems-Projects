/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:35:22 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/21 03:34:32 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_player_up(t_game *game)
{
	int		x;
	int		y;
	char	*str_moves;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	lose_up(game, x, y);
	win_up(game, x, y);
	if (game->map.map[y - 1][x] != WALL && game->map.map[y - 1][x] != EXIT)
	{
		if (game->map.map[y - 1][x] == COLLECTIBLE)
			game->map.collectibles--;
		game->map.map[y][x] = EMPTY;
		game->map.map[y - 1][x] = PLAYER;
		game->map.player_pos.y--;
		draw_map(game);
		game->moves++;
		str_moves = ft_itoa(game->moves);
		mlx_string_put(game->mlx, game->win, 60, 25, 0x000FF0, "MOVES");
		mlx_string_put(game->mlx, game->win, 100, 25, 0x000FF0, str_moves);
		free(str_moves);
	}
	draw_player(game, 'u');
}

void	ft_player_left(t_game *game)
{
	int		x;
	int		y;
	char	*str_moves;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	lose_left(game, x, y);
	win_left(game, x, y);
	if (game->map.map[y][x - 1] != WALL && game->map.map[y][x - 1] != EXIT)
	{
		if (game->map.map[y][x - 1] == COLLECTIBLE)
			game->map.collectibles--;
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x - 1] = PLAYER;
		game->map.player_pos.x--;
		if (game->map.map[y][x - 1] == COLLECTIBLE)
			game->map.collectibles--;
		draw_map(game);
		game->moves++;
		str_moves = ft_itoa(game->moves);
		mlx_string_put(game->mlx, game->win, 60, 25, 0x000FF0, "MOVES");
		mlx_string_put(game->mlx, game->win, 100, 25, 0x000FF0, str_moves);
		free(str_moves);
	}
	draw_player(game, 'l');
}

void	ft_player_down(t_game *game)
{
	int		x;
	int		y;
	char	*str_moves;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	lose_down(game, x, y);
	win_down(game, x, y);
	if (game->map.map[y + 1][x] != WALL && game->map.map[y + 1][x] != EXIT)
	{
		if (game->map.map[y + 1][x] == COLLECTIBLE)
			game->map.collectibles--;
		game->map.map[y][x] = EMPTY;
		game->map.map[y + 1][x] = PLAYER;
		game->map.player_pos.y++;
		draw_map(game);
		game->moves++;
		str_moves = ft_itoa(game->moves);
		mlx_string_put(game->mlx, game->win, 60, 25, 0x000FF0, "MOVES");
		mlx_string_put(game->mlx, game->win, 100, 25, 0x000FF0, str_moves);
		free(str_moves);
	}
	draw_player(game, 'd');
}

void	ft_player_right(t_game *game)
{
	int		x;
	int		y;
	char	*str_moves;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	lose_right(game, x, y);
	win_right(game, x, y);
	if (game->map.map[y][x + 1] != WALL && game->map.map[y][x + 1] != EXIT)
	{
		if (game->map.map[y][x + 1] == COLLECTIBLE)
			game->map.collectibles--;
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x + 1] = PLAYER;
		game->map.player_pos.x++;
		draw_map(game);
		game->moves++;
		str_moves = ft_itoa(game->moves);
		mlx_string_put(game->mlx, game->win, 60, 25, 0x000FF0, "MOVES");
		mlx_string_put(game->mlx, game->win, 100, 25, 0x000FF0, str_moves);
		free(str_moves);
	}
	draw_player(game, 'r');
}
