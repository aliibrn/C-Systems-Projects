/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:42:38 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/25 00:11:52 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	calcul_enemy(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->map.map[y][x] == MONSTER)
			{
				game->map.monst += 1;
			}
			x++;
		}
		y++;
	}
}

static void	calcul_elements_1(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->map.map[y][x] == EMPTY)
				game->map.empty += 1;
			if (game->map.map[y][x] == PLAYER)
			{
				game->map.player += 1;
				game->map.player_pos.x = x;
				game->map.player_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

static void	calcul_elements_2(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (game->map.map[y][x] == EXIT)
				game->map.exit += 1;
			if (game->map.map[y][x] == COLLECTIBLE)
			{
				game->map.collectibles += 1;
				game->map.collectibles1 += 1;
			}
			x++;
		}
		y++;
	}
}

void	check_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			if (ft_strchr("EP01CMK", game->map.map[y][x]) == NULL)
				alert(game, "[COMPONENT ERROR]-ENTER A VALID COMPONENT!");
			x++;
		}
		y++;
	}
	calcul_elements_1(game);
	calcul_elements_2(game);
	calcul_enemy(game);
}
