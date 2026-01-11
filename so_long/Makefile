# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbouram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 21:04:34 by abbouram          #+#    #+#              #
#    Updated: 2024/02/24 22:42:12 by abbouram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address 

LFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz

INCLUDE = so_long.h ./libft/libft.h

INCLUDE_BONUS = so_long_bonus.h ./libft/libft.h

LIBFT = ./libft/

SRCS = ./mandatory/so_long.c \
       ./mandatory/map_valid.c \
		./mandatory/check_map.c \
		./mandatory/utils.c \
		./mandatory/draw_map.c \
		./mandatory/update_player.c \
		./mandatory/check_conditions.c \
		./mandatory/check_elements.c \
		./mandatory/utils2.c \
		./mandatory/win.c \
		./mandatory/error_load.c \

SRCS_BONUS = ./bonus/so_long_bonus.c \
		./bonus/map_valid_bonus.c \
		./bonus/check_map_bonus.c \
		./bonus/utils_bonus.c \
		./bonus/draw_map_bonus.c \
		./bonus/update_player_bonus.c \
		./bonus/check_conditions_bonus.c \
		./bonus/check_elements_bonus.c \
		./bonus/utils2_bonus.c \
		./bonus/win_bonus.c \
		./bonus/animation_bonus.c \
		./bonus/lose_bonus.c \
		./bonus/monster_bonus.c \
		./bonus/draw_bonus.c \
		./bonus/error_load_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o:
	 $(CC) $(CFLAGS) -c $< -o $@


PURPLE = \033[1;35m
WHITE = \033[1;37m
CYAN= \033[0;36m

all: $(NAME)


$(NAME) : $(OBJS) $(INCLUDE)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME) $(LFLAGS)
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
	@echo "$(PURPLE)The Makefile of [$(CYAN)SO_LONG$(PURPLE)] has been compiled!🤠"


bonus : $(NAME_BONUS)


$(NAME_BONUS) : $(OBJS_BONUS) $(INCLUDE_BONUS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS_BONUS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME_BONUS) $(LFLAGS)
	@echo "$(PURPLE)The Makefile of [$(CYAN)SO_LONG_BONUS$(PURPLE)] has been compiled!🤠"


clean:
	@make fclean -C $(LIBFT)
	@rm -f $(OBJS) $(OBJS_BONUS)


fclean: clean
	@echo "$(WHITE)   Cleaning all... 🧹"
	@make fclean -C $(LIBFT)
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(WHITE)✨ Cleaning complete! ✨"


re: fclean all
rebonus: fclean bonus


.PHONY: all clean fclean re rebonus
