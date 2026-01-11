/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:49:48 by abbouram          #+#    #+#             */
/*   Updated: 2024/02/21 02:52:44 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EMPTY '0'
# define ENEMY 'M'
# define MONSTER 'K'

# define W_UP "./bonus/XPM_FILES/using/wall/wall_up.xpm"
# define W_D "./bonus/XPM_FILES/using/wall/wall_down.xpm"
# define W_L "./bonus/XPM_FILES/using/wall/wall_left.xpm"
# define W_R "./bonus/XPM_FILES/using/wall/wall_right.xpm"
# define OU "./bonus/XPM_FILES/using/wall/else.xpm"
# define QU "./bonus/XPM_FILES/using/wall/qunt.xpm"
# define E "./bonus/XPM_FILES/using/empty/empty.xpm"
# define P_U "./bonus/XPM_FILES/using/player1/up_player.xpm"
# define P_R "./bonus/XPM_FILES/using/player1/right_player.xpm"
# define P_L "./bonus/XPM_FILES/using/player1/left_player.xpm"
# define P_D "./bonus/XPM_FILES/using/player1/down_player.xpm"
# define P_EX "./bonus/XPM_FILES/using/Exit/exit.xpm"

# define ESC 65307
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>

# define C1 "./bonus/XPM_FILES/using/coin2/coin_1.xpm"
# define C2 "./bonus/XPM_FILES/using/coin2/coin_2.xpm"
# define C3 "./bonus/XPM_FILES/using/coin2/coin_3.xpm"
# define C4 "./bonus/XPM_FILES/using/coin2/coin_4.xpm"
# define C5 "./bonus/XPM_FILES/using/coin2/coin_5.xpm"
# define C6 "./bonus/XPM_FILES/using/coin2/coin_6.xpm"
# define C7 "./bonus/XPM_FILES/using/coin2/coin_7.xpm"
# define C8 "./bonus/XPM_FILES/using/coin2/coin_8.xpm"
# define C9 "./bonus/XPM_FILES/using/coin2/coin_9.xpm"

# define M1 "./bonus/XPM_FILES/using/trap/trap_1.xpm"
# define M2 "./bonus/XPM_FILES/using/trap/trap_2.xpm"
# define M3	"./bonus/XPM_FILES/using/trap/trap_3.xpm"
# define M4	"./bonus/XPM_FILES/using/trap/trap_4.xpm"
# define M5 "./bonus/XPM_FILES/using/trap/trap_5.xpm"
# define M6 "./bonus/XPM_FILES/using/trap/trap_6.xpm"
# define M7 "./bonus/XPM_FILES/using/trap/trap_7.xpm"
# define M8 "./bonus/XPM_FILES/using/trap/trap_8.xpm"

# define K1 "./bonus/XPM_FILES/using/enemy/enemy_1.xpm"
# define K2 "./bonus/XPM_FILES/using/enemy/enemy_2.xpm"
# define K3 "./bonus/XPM_FILES/using/enemy/enemy_3.xpm"
# define K4 "./bonus/XPM_FILES/using/enemy/enemy_4.xpm"
# define K5 "./bonus/XPM_FILES/using/enemy/enemy_5.xpm"
# define K6 "./bonus/XPM_FILES/using/enemy/enemy_6.xpm"
# define K7 "./bonus/XPM_FILES/using/enemy/enemy_7.xpm"
# define K8 "./bonus/XPM_FILES/using/enemy/enemy_8.xpm"
# define K9 "./bonus/XPM_FILES/using/enemy/enemy_9.xpm"
# define K10 "./bonus/XPM_FILES/using/enemy/enemy_10.xpm"
# define K11 "./bonus/XPM_FILES/using/enemy/enemy_11.xpm"
# define K12 "./bonus/XPM_FILES/using/enemy/enemy_12.xpm"
# define K13 "./bonus/XPM_FILES/using/enemy/enemy_13.xpm"
# define K14 "./bonus/XPM_FILES/using/enemy/enemy_14.xpm"
# define K15 "./bonus/XPM_FILES/using/enemy/enemy_15.xpm"
# define K16 "./bonus/XPM_FILES/using/enemy/enemy_16.xpm"

# define UP 0
# define DOWN 1

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_moster;

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
	int			monst;
	t_point		player_pos;
	t_moster	monster;
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
	void	*t_collec[9];
	void	*t_exit;
	void	*t_player[4];
	void	*t_enemy[6];
	void	*monster[16];
}	t_txt;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		moves;
	t_map	map;
	t_txt	txt;
}	t_game;

int		error_load1(t_game *game);
int		error_load2(t_game *game);
int		handle_window_close(void);
int		ft_animation(t_game *game);
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
void	set_enemy(t_game *game);
void	lose_up(t_game *game, int x, int y);
void	lose_left(t_game *game, int x, int y);
void	lose_down(t_game *game, int x, int y);
void	lose_right(t_game *game, int x, int y);
void	you_lose(t_game *game);
void	put_monster(t_game *game);
void	ft_draw(t_game *game);
void	check_xpm(t_game *game);
int		check_monster(t_game *game);

#endif
