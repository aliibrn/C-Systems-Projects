/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:57:58 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/20 23:45:54 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	enemy(t_game *game)
{
	static int	frame;
	int			y;
	int			x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->map.map[y][x] == ENEMY)
				mlx_put_image_to_window(game->mlx, game->win,
					game->txt.t_enemy[frame], x * 48, y * 48);
			x++;
		}
		y++;
	}
	frame++;
	if (frame >= 6)
		frame = 0;
}

void	coin(t_game *game)
{
	static int	frame;
	int			y;
	int			x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->map.map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->win,
					game->txt.t_collec[frame], x * 48, y * 48);
			x++;
		}
		y++;
	}
	frame++;
	if (frame >= 9)
		frame = 0;
}

int	ft_animation(t_game *game)
{
	static int	b = 1;
	static int	a = 1;

	if (b % 10000 == 0)
	{
		enemy(game);
		coin(game);
		b = 1;
	}
	b++;
	if (a % 20000 == 0)
	{
		put_monster(game);
		a = 1;
	}
	a++;
	return (0);
}
