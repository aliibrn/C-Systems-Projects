/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:45:26 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/21 02:47:41 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_texture(t_game *game)
{
	int	size;

	size = 48;
	game->txt.wall_up = mlx_xpm_file_to_image(game->mlx, W_UP, &size, &size);
	game->txt.wall_down = mlx_xpm_file_to_image(game->mlx, W_D, &size, &size);
	game->txt.wall_gauche = mlx_xpm_file_to_image(game->mlx, W_L, &size, &size);
	game->txt.wall_droit = mlx_xpm_file_to_image(game->mlx, W_R, &size, &size);
	game->txt.t_empty = mlx_xpm_file_to_image(game->mlx, E, &size, &size);
	game->txt.qunt = mlx_xpm_file_to_image(game->mlx, QU, &size, &size);
	game->txt.otherr = mlx_xpm_file_to_image(game->mlx, OU, &size, &size);
	game->txt.t_exit = mlx_xpm_file_to_image(game->mlx, P_EX, &size, &size);
	game->txt.t_player[0] = mlx_xpm_file_to_image(game->mlx, P_U, &size, &size);
	game->txt.t_player[1] = mlx_xpm_file_to_image(game->mlx, P_L, &size, &size);
	game->txt.t_player[2] = mlx_xpm_file_to_image(game->mlx, P_R, &size, &size);
	game->txt.t_player[3] = mlx_xpm_file_to_image(game->mlx, P_D, &size, &size);
	game->txt.t_collec = mlx_xpm_file_to_image(game->mlx, C, &size, &size);
}

int	error_load(t_game *game)
{
	if (game->txt.wall_up == NULL || game->txt.wall_down == NULL
		|| game->txt.wall_gauche == NULL || game->txt.wall_droit == NULL
		|| game->txt.t_empty == NULL || game->txt.qunt == NULL
		|| game->txt.otherr == NULL || game->txt.t_exit == NULL
		|| game->txt.t_player[0] == NULL || game->txt.t_player[1] == NULL
		|| game->txt.t_player[2] == NULL || game->txt.t_player[3] == NULL
		|| game->txt.t_collec == NULL)
		return (0);
	return (1);
}

void	check_xpm(t_game *game)
{
	if (!error_load(game))
		alert(game, "LOADING XPM ERROR");
}
