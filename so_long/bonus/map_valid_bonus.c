/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:01:21 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/25 00:12:13 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	valid_form(t_game *game)
{
	int	len;
	int	i;

	len = game->map.x;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if ((int)ft_strlen(game->map.map[i]) != (int)len)
			alert(game, "[MAP FORMAT] - PLEASE ENTER A VALID MAP FORMAT !");
		i++;
	}
}

static void	error_elements(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		alert(game, "[COMPONENT ERROR] - ENTER A VALID NBR COMPONENT EXIT !");
	if (game->map.player == 0 || game->map.player > 1)
		alert(game, "[COMPONENT ERROR] - PLEASE ENTER A VALID NBR PLAYERS !");
	if (game->map.collectibles == 0)
		alert(game, "[COMPONENT ERROR] - ENTER AT LEAST 1 COLLECTIBLE !");
}

static void	is_closed(t_map *map, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		if (map->map[y][0] != WALL)
			alert(game, "[MAP NOT CLOSED] - PLEASE CLOSE THE MAP TO PLAY !");
		if (map->map[y][map->x - 1] != WALL)
			alert(game, "[MAP NOT CLOSED] - PLEASE CLOSE THE MAP TO PLAY !");
		y++;
	}
	while (x < map->x)
	{
		if (map->map[0][x] != WALL)
			alert(game, "[MAP NOT CLOSED] - PLEASE CLOSE THE MAP TO PLAY !");
		if (map->map[map->y - 1][x] != WALL)
			alert(game, "[MAP NOT CLOSED] - PLEASE CLOSE THE MAP TO PLAY !");
		x++;
	}
}

void	map_is_valid(t_game *game)
{
	valid_form(game);
	check_elements(game);
	error_elements(game);
	is_closed(&game->map, game);
	flood_fill_collectible(game);
	flood_fill_path(game);
	check_xpm(game);
}
