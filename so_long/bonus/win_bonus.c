/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:26:45 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/16 21:33:18 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	you_win(t_game *game)
{
	ft_printf("YOU WIN\n");
	ft_destroy(game);
}

void	win_up(t_game *game, int x, int y)
{
	if (game->map.map[y - 1][x] == EXIT && game->map.collectibles == 0)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y - 1][x] = PLAYER;
		game->map.player_pos.x++;
		draw_map(game);
		you_win(game);
	}
}

void	win_left(t_game *game, int x, int y)
{
	if (game->map.map[y][x - 1] == EXIT && game->map.collectibles == 0)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x - 1] = PLAYER;
		game->map.player_pos.x++;
		draw_map(game);
		you_win(game);
	}
}

void	win_down(t_game *game, int x, int y)
{
	if (game->map.map[y + 1][x] == EXIT && game->map.collectibles == 0)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y + 1][x] = PLAYER;
		game->map.player_pos.x++;
		draw_map(game);
		you_win(game);
	}
}

void	win_right(t_game *game, int x, int y)
{
	if (game->map.map[y][x + 1] == EXIT && game->map.collectibles == 0)
	{
		game->map.map[y][x] = EMPTY;
		game->map.map[y][x + 1] = PLAYER;
		game->map.player_pos.x++;
		draw_map(game);
		you_win(game);
	}
}
