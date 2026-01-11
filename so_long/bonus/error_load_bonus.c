/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:53:02 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/21 02:56:00 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	error_load1(t_game *game)
{
	if (game->txt.t_enemy[0] == NULL || game->txt.t_enemy[1] == NULL
		|| game->txt.t_enemy[2] == NULL || game->txt.t_enemy[3] == NULL
		|| game->txt.t_enemy[4] == NULL || game->txt.t_enemy[5] == NULL
		|| game->txt.monster[0] == NULL || game->txt.monster[1] == NULL
		|| game->txt.monster[2] == NULL || game->txt.monster[3] == NULL
		|| game->txt.monster[4] == NULL || game->txt.monster[5] == NULL
		|| game->txt.monster[6] == NULL || game->txt.monster[7] == NULL
		|| game->txt.monster[8] == NULL || game->txt.monster[9] == NULL
		|| game->txt.monster[10] == NULL || game->txt.monster[11] == NULL
		|| game->txt.monster[12] == NULL || game->txt.monster[13] == NULL
		|| game->txt.monster[14] == NULL || game->txt.monster[15] == NULL)
		return (0);
	return (1);
}

int	error_load2(t_game *game)
{
	if (game->txt.wall_up == NULL || game->txt.wall_down == NULL
		|| game->txt.wall_gauche == NULL || game->txt.wall_droit == NULL
		|| game->txt.t_empty == NULL || game->txt.qunt == NULL
		|| game->txt.otherr == NULL || game->txt.t_exit == NULL
		|| game->txt.t_player[0] == NULL || game->txt.t_player[1] == NULL
		|| game->txt.t_player[2] == NULL || game->txt.t_player[3] == NULL
		|| game->txt.t_collec[0] == NULL || game->txt.t_collec[1] == NULL
		|| game->txt.t_collec[2] == NULL || game->txt.t_collec[3] == NULL
		|| game->txt.t_collec[4] == NULL || game->txt.t_collec[5] == NULL
		|| game->txt.t_collec[6] == NULL || game->txt.t_collec[7] == NULL
		|| game->txt.t_collec[8] == NULL)
		return (0);
	return (1);
}

void	check_xpm(t_game *game)
{
	set_texture(game);
	set_enemy(game);
	if (!error_load1(game))
		alert(game, "LOADING XPM ERROR");
	if (!error_load2(game))
		alert(game, "LOADING XPM ERROR");
}
