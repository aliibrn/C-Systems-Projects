NAME = so_long

SRCS = so_long_bonus.c \
		map_valid_bonus.c \
		check_map_bonus.c \
		utils_bonus.c \
		draw_map_bonus.c \
		update_player_bonus.c \
		check_conditions_bonus.c \
		check_elements_bonus.c \
		utils2_bonus.c \
		win_bonus.c \
		animation_bonus.c \
		lose_bonus.c \
		monster_bonus.c \
		draw_bonus.c \
		error_load_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o);

CFLAGS =  -Wall -Wextra -Werror -I/usr/include -I./minilibx-linux -O3 

LDFLAGS = -L./minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

libft = ../libft/libft.a 

CC = gcc 

%.o: %.c
	 $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(libft)
	$(CC) $(OBJS) $(LDFLAGS) $(libft) -o $(NAME)
	@echo  "\[\033[4;35m                                                          \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "\[\033[4;35mBuild complete: $(NAME)\033[0m"

all: $(NAME)


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
	
