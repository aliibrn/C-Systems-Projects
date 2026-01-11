/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:47:33 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/20 02:48:34 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	you_lose(t_game *game)
{
	ft_printf("Khsarty aka3ka3\n");
	ft_destroy(game);
}

void	lose_up(t_game *game, int x, int y)
{
	if (game->map.map[y - 1][x] == ENEMY)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y - 1][x] = PLAYER;
		game->map.player_pos.y--;
		draw_map(game);
		you_lose(game);
	}
	if (game->map.map[y - 1][x] == MONSTER)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y - 1][x] = MONSTER;
		game->map.player_pos.y--;
		draw_map(game);
		you_lose(game);
	}
}

void	lose_left(t_game *game, int x, int y)
{
	if (game->map.map[y][x - 1] == ENEMY)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x - 1] = PLAYER;
		game->map.player_pos.x--;
		draw_map(game);
		you_lose(game);
	}
	if (game->map.map[y][x - 1] == MONSTER)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x - 1] = MONSTER;
		game->map.player_pos.x--;
		draw_map(game);
		you_lose(game);
	}
}

void	lose_down(t_game *game, int x, int y)
{
	if (game->map.map[y + 1][x] == ENEMY)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y + 1][x] = PLAYER;
		game->map.player_pos.y++;
		draw_map(game);
		you_lose(game);
	}
	if (game->map.map[y + 1][x] == MONSTER)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y + 1][x] = MONSTER;
		game->map.player_pos.y++;
		draw_map(game);
		you_lose(game);
	}
}

void	lose_right(t_game *game, int x, int y)
{
	if (game->map.map[y][x + 1] == ENEMY)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x + 1] = PLAYER;
		game->map.player_pos.x++;
		draw_map(game);
		you_lose(game);
	}
	if (game->map.map[y][x + 1] == MONSTER)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x + 1] = MONSTER;
		game->map.player_pos.x++;
		draw_map(game);
		you_lose(game);
	}
}
