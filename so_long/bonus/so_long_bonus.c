/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:36:20 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/20 02:45:31 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.mlx = mlx_init();
	if (ac == 1)
	{
		ft_printf("Error\n");
		ft_printf("PLEASE ENTER A MAP FILE");
		return (0);
	}
	if (args_is_valid(ac, av) == 1)
	{
		game_init(&game);
		get_map(av[1], &game);
		map_is_valid(&game);
		game.win = mlx_new_window(game.mlx,
				game.map.x * 48, game.map.y * 48, "so_long");
		ft_draw(&game);
		mlx_loop_hook(game.mlx, ft_animation, &game);
		mlx_hook(game.win, 2, 1L >> 0, key_hook, &game);
		mlx_hook(game.win, 17, 0, handle_window_close, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
