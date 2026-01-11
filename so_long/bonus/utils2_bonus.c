/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:41:04 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/20 02:27:47 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_enemy(t_game *game)
{
	int	size;

	size = 48;
	game->txt.t_enemy[0] = mlx_xpm_file_to_image(game->mlx, M1, &size, &size);
	game->txt.t_enemy[1] = mlx_xpm_file_to_image(game->mlx, M2, &size, &size);
	game->txt.t_enemy[2] = mlx_xpm_file_to_image(game->mlx, M3, &size, &size);
	game->txt.t_enemy[3] = mlx_xpm_file_to_image(game->mlx, M4, &size, &size);
	game->txt.t_enemy[4] = mlx_xpm_file_to_image(game->mlx, M5, &size, &size);
	game->txt.t_enemy[5] = mlx_xpm_file_to_image(game->mlx, M6, &size, &size);
	game->txt.monster[0] = mlx_xpm_file_to_image(game->mlx, K1, &size, &size);
	game->txt.monster[1] = mlx_xpm_file_to_image(game->mlx, K2, &size, &size);
	game->txt.monster[2] = mlx_xpm_file_to_image(game->mlx, K3, &size, &size);
	game->txt.monster[3] = mlx_xpm_file_to_image(game->mlx, K4, &size, &size);
	game->txt.monster[4] = mlx_xpm_file_to_image(game->mlx, K5, &size, &size);
	game->txt.monster[5] = mlx_xpm_file_to_image(game->mlx, K6, &size, &size);
	game->txt.monster[6] = mlx_xpm_file_to_image(game->mlx, K6, &size, &size);
	game->txt.monster[7] = mlx_xpm_file_to_image(game->mlx, K7, &size, &size);
	game->txt.monster[8] = mlx_xpm_file_to_image(game->mlx, K8, &size, &size);
	game->txt.monster[9] = mlx_xpm_file_to_image(game->mlx, K9, &size, &size);
	game->txt.monster[10] = mlx_xpm_file_to_image(game->mlx, K10, &size, &size);
	game->txt.monster[11] = mlx_xpm_file_to_image(game->mlx, K11, &size, &size);
	game->txt.monster[12] = mlx_xpm_file_to_image(game->mlx, K12, &size, &size);
	game->txt.monster[13] = mlx_xpm_file_to_image(game->mlx, K13, &size, &size);
	game->txt.monster[14] = mlx_xpm_file_to_image(game->mlx, K14, &size, &size);
	game->txt.monster[15] = mlx_xpm_file_to_image(game->mlx, K15, &size, &size);
}

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
	game->txt.t_collec[0] = mlx_xpm_file_to_image(game->mlx, C1, &size, &size);
	game->txt.t_collec[1] = mlx_xpm_file_to_image(game->mlx, C2, &size, &size);
	game->txt.t_collec[2] = mlx_xpm_file_to_image(game->mlx, C3, &size, &size);
	game->txt.t_collec[3] = mlx_xpm_file_to_image(game->mlx, C4, &size, &size);
	game->txt.t_collec[4] = mlx_xpm_file_to_image(game->mlx, C5, &size, &size);
	game->txt.t_collec[5] = mlx_xpm_file_to_image(game->mlx, C6, &size, &size);
	game->txt.t_collec[6] = mlx_xpm_file_to_image(game->mlx, C7, &size, &size);
	game->txt.t_collec[7] = mlx_xpm_file_to_image(game->mlx, C8, &size, &size);
	game->txt.t_collec[8] = mlx_xpm_file_to_image(game->mlx, C9, &size, &size);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < game->map.y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	handle_window_close(void)
{
	exit(0);
	return (0);
}
