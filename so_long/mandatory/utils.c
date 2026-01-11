/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:42:28 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/16 20:49:00 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	args_is_valid(int ac, char **av)
{
	int	len;

	len = 0;
	if (ac != 2)
	{
		ft_printf("Error\n");
		ft_printf("[ARGS ERROR] - PLEASE ENTER A VALID NBR ARGS !\n");
		return (0);
	}
	len = ft_strlen(av[1]) - 4;
	if (ft_strncmp(".ber", &av[1][len], 4) != 0)
	{
		ft_printf("Error\n");
		ft_printf("[MAP FILE] - PLEASE ENTER A VALID MAP FILE !\n");
		return (0);
	}
	return (1);
}

int	key_hook(int key, t_game *game)
{
	if (key == ESC || key == Q)
		ft_destroy(game);
	if (key == W)
		ft_player_up(game);
	if (key == S)
		ft_player_down(game);
	if (key == A)
		ft_player_left(game);
	if (key == D)
		ft_player_right(game);
	return (0);
}

void	ft_destroy(t_game *game)
{
	(void)game;
	exit(0);
}

void	alert(t_game *game, char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	ft_destroy(game);
}

void	game_init(t_game *game)
{
	game->moves = 0;
	game->map.collectibles1 = 0;
	game->map.y = 0;
	game->map.x = 0;
	game->map.empty = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->txt.wall_up = NULL;
	game->txt.wall_down = NULL;
	game->txt.wall_gauche = NULL;
	game->txt.wall_droit = NULL;
	game->txt.t_empty = NULL;
	game->txt.qunt = NULL;
	game->txt.otherr = NULL;
	game->txt.t_exit = NULL;
	game->txt.t_player[0] = NULL;
	game->txt.t_player[1] = NULL;
	game->txt.t_player[2] = NULL;
	game->txt.t_player[3] = NULL;
	game->txt.t_collec = NULL;
}
