/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:54:23 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/16 23:55:20 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	get_map_lines(char *map_file, t_game *game)
{
	int		count_lines;
	int		map_fd;
	char	*temp;

	count_lines = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		alert(game, "	!!!!!!! OPEN MAP FILE ERROR !!!!!!!");
	temp = get_next_line(map_fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(map_fd);
		count_lines++;
	}
	if (count_lines == 0)
		alert(game, "	!!!!!!! EMPTY MAP FILE ERROR !!!!!!!");
	game->map.y = count_lines;
	close(map_fd);
}

static void	store_map(char *map_file, t_game *game)
{
	int		map_fd;
	int		i;
	char	**temp;

	i = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		alert(game, "!!!!!!! OPEN MAP FILE ERROR !!!!!!!");
	game->map.map = malloc((game->map.y + 1) * sizeof(char *));
	temp = malloc((game->map.y + 1) * sizeof(char *));
	if (!game->map.map)
		alert(game, "	!!!!!!! MALLOC ERROR [1] !!!!!!!");
	while (i < game->map.y)
		temp[i++] = get_next_line(map_fd);
	close(map_fd);
	i = 0;
	while (i < game->map.y)
	{
		game->map.map[i] = ft_strtrim(temp[i], "\n");
		i++;
	}
	game->map.map[i] = NULL;
	game->map.x = ft_strlen(game->map.map[0]);
	free_map(temp, game);
}

void	get_map(char *map_file, t_game *game)
{
	get_map_lines(map_file, game);
	store_map(map_file, game);
}
