NAME = so_long

SRCS = so_long.c \
       map_valid.c \
	check_map.c \
	utils.c \
	draw_map.c \
	update_player.c \
	check_conditions.c \
	check_elements.c \
	utils2.c \
	win.c \
	error_load.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o);

CFLAGS = -Wall -Wextra -Werror -I/usr/include -I./minilibx-linux -O3 

LDFLAGS = -L./minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

libft = ../libft/libft.a 

CC = gcc 

%.o: %.c
	 $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(libft)
	$(CC) $(OBJS) $(LDFLAGS) $(libft) -o $(NAME)
	

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
	
