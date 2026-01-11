/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:36:20 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/16 20:40:15 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 1)
	{
		ft_printf("Error\n");
		ft_printf("[MAP] PLEASE ENTER A MAP TO PLAY !\n");
		return (0);
	}
	if (args_is_valid(ac, av) == 1)
	{
		game.mlx = mlx_init();
		game_init(&game);
		get_map(av[1], &game);
		map_is_valid(&game);
		game.win = mlx_new_window(game.mlx,
				game.map.x * 48, game.map.y * 48, "so_long");
		draw_map(&game);
		mlx_hook(game.win, 2, 1L >> 0, key_hook, &game);
		mlx_hook(game.win, 17, 0, handle_window_close, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
