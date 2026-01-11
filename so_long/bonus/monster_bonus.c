/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:10:11 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/25 00:42:18 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_monster(t_game *game)
{
	int	y;
	int	x;

	y = game->map.monster.y;
	x = game->map.monster.x;
	if (game->map.map[y - 1][x] == WALL && game->map.map[y + 1][x] == WALL)
		return (0);
	else
		return (1);
}

void	update(int new_y, int x, int y, t_game *game)
{
	static int	f = 0;

	game->map.map[y][x] = EMPTY;
	mlx_put_image_to_window(game->mlx, game->win,
		game->txt.t_empty, x * 48, y * 48);
	game->map.map[new_y][x] = MONSTER;
	mlx_put_image_to_window(game->mlx, game->win,
		game->txt.monster[f], x * 48, new_y * 48);
	game->map.monster.y = new_y;
	f++;
	if (f >= 15)
		f = 0;
}

void	fly_monster(t_game *game, int x, int y)
{
	static int	direction = DOWN;
	int			new_y;

	if (direction == UP)
		new_y = y - 1;
	else
		new_y = y + 1;
	if (game->map.map[new_y][x] == PLAYER)
		you_lose(game);
	if (new_y >= 0 && new_y < game->map.y && game->map.map[new_y][x] != WALL
		&& game->map.map[new_y][x] != EXIT
		&& game->map.map[new_y][x] != COLLECTIBLE
		&& game->map.map[new_y][x] != ENEMY)
		update(new_y, x, y, game);
	else
	{
		if (direction == UP)
			direction = DOWN;
		else
			direction = UP;
	}
}

void	update_monster_position(t_game *game, int x, int y)
{
	if (check_monster(game))
	{
		fly_monster(game, x, y);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->txt.monster[0], x * 48, y * 48);
}

void	put_monster(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (++y < game->map.y)
	{
		x = 0;
		while (++x < game->map.x)
		{
			if (game->map.map[y][x] == MONSTER)
			{
				if (game->map.monst == 1)
				{
					game->map.monster.x = x;
					game->map.monster.y = y;
					update_monster_position(game,
						game->map.monster.x, game->map.monster.y);
				}
				else
					mlx_put_image_to_window(game->mlx, game->win,
						game->txt.monster[0], x * 48, y * 48);
			}
		}
	}
}
