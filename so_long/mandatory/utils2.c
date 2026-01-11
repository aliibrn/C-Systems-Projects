/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:41:04 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/22 19:11:22 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	you_win(t_game *game)
{
	ft_printf("YOU WIN\n");
	ft_destroy(game);
}

int	handle_window_close(void)
{
	exit(0);
	return (0);
}
