/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:01:47 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/16 03:36:47 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static char	**copy_map(t_game *game)
{
	int		i;
	char	**dub;

	i = 0;
	dub = malloc((game->map.y + 1) * sizeof(char *));
	if (!dub)
		alert(game, "[MALLOC DUB ERROR]");
	while (i < game->map.y)
	{
		dub[i] = ft_strdup(game->map.map[i]);
		if (!dub[i])
		{
			free_map(dub, game);
			alert(game, "[MALLOC DUB ERROR 2]");
		}
		i++;
	}
	return (dub);
}

static int	check_path(t_game *game, char **map, int x, int y)
{
	int	result;

	if (x < 0 || x > game->map.x || y < 0
		|| y > game->map.y || map[y][x] == WALL || map[y][x] == 'V')
		return (0);
	if (map[y][x] == EXIT)
		return (1);
	map[y][x] = 'V';
	result = check_path (game, map, x - 1, y)
		|| check_path (game, map, x + 1, y)
		|| check_path (game, map, x, y - 1)
		|| check_path (game, map, x, y + 1);
	if (result == 1)
		return (1);
	return (0);
}

static int	check_collectible(t_game *game, char **map, int x, int y)
{
	int	result;

	if (x < 0 || x >= game->map.x || y < 0 || y >= game->map.y
		|| map[y][x] == WALL || map[y][x] == EXIT || map[y][x] == 'V')
		return (0);
	if (map[y][x] == COLLECTIBLE)
		game->map.collectibles1--;
	if (game->map.collectibles1 == 0)
		return (1);
	map[y][x] = 'V';
	result = check_collectible (game, map, x - 1, y)
		|| check_collectible (game, map, x + 1, y)
		|| check_collectible (game, map, x, y - 1)
		|| check_collectible (game, map, x, y + 1);
	if (result == 1)
		return (1);
	return (0);
}

void	flood_fill_collectible(t_game *game)
{
	int		i;
	int		j;
	char	**dup;

	dup = copy_map(game);
	i = game->map.player_pos.x;
	j = game->map.player_pos.y;
	if (!check_collectible(game, dup, i, j))
	{
		free_map(dup, game);
		alert(game, "hamouda mo7asar f makla");
	}
	free_map(dup, game);
}

void	flood_fill_path(t_game *game)
{
	char	**dub;
	int		i;
	int		j;

	dub = copy_map(game);
	i = game->map.player_pos.x;
	j = game->map.player_pos.y;
	if (!check_path (game, dub, i, j))
	{
		free_map(dub, game);
		alert(game, "hamouda mo7asar");
	}
	free_map(dub, game);
}
