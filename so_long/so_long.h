/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:49:48 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/21 00:22:36 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EMPTY '0'

# define W_UP "./mandatory/XPM_FILES/using/wall/wall_up.xpm"
# define W_D "./mandatory/XPM_FILES/using/wall/wall_down.xpm"
# define W_L "./mandatory/XPM_FILES/using/wall/wall_left.xpm"
# define W_R "./mandatory/XPM_FILES/using/wall/wall_right.xpm"
# define OU "./mandatory/XPM_FILES/using/wall/else.xpm"
# define QU "./mandatory/XPM_FILES/using/wall/qunt.xpm"
# define E "./mandatory/XPM_FILES/using/empty/empty.xpm"
# define C "./mandatory/XPM_FILES/using/coin2/coin_1.xpm"
# define P_U "./mandatory/XPM_FILES/using/player1/up_player.xpm"
# define P_R "./mandatory/XPM_FILES/using/player1/right_player.xpm"
# define P_L "./mandatory/XPM_FILES/using/player1/left_player.xpm"
# define P_D "./mandatory/XPM_FILES/using/player1/down_player.xpm"
# define P_EX "./mandatory/XPM_FILES/using/Exit/exit.xpm"

# define ESC 65307
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100

# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	int			y;
	int			x;
	int			collectibles;
	int			collectibles1;
	int			exit;
	int			player;
	int			empty;
	t_point		player_pos;
	char		**map;
}	t_map;

typedef struct s_txt
{
	void	*wall_droit;
	void	*wall_gauche;
	void	*wall_down;
	void	*wall_up;
	void	*qunt;
	void	*otherr;
	void	*t_empty;
	void	*t_collec;
	void	*t_exit;
	void	*t_player[4];
}	t_txt;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		moves;
	t_map	map;
	t_txt	txt;
}	t_game;

int		handle_window_close(void);
int		args_is_valid(int argc, char **argv);
int		key_hook(int key, t_game *game);
void	game_init(t_game *game);
void	ft_destroy(t_game *game);
void	alert(t_game *game, char *str);
void	get_map(char *map_file, t_game *game);
void	map_is_valid(t_game *game);
void	draw_map(t_game *game);
void	set_texture(t_game *game);
void	ft_player_right(t_game *game);
void	ft_player_down(t_game *game);
void	ft_player_left(t_game *game);
void	ft_player_up(t_game *game);
void	draw_player(t_game *game, char direction);
void	flood_fill_collectible(t_game *game);
void	flood_fill_path(t_game *game);
void	free_map(char **map, t_game *game);
void	check_elements(t_game *game);
void	win_up(t_game *game, int x, int y);
void	win_left(t_game *game, int x, int y);
void	win_down(t_game *game, int x, int y);
void	win_right(t_game *game, int x, int y);
void	you_win(t_game *game);
void	check_xpm(t_game *game);
void	destroy_img(t_game *game);

#endif
