# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbouram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 02:02:34 by abbouram          #+#    #+#              #
#    Updated: 2024/04/06 02:02:36 by abbouram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

SERVER_SRCS = ./mandatory/server.c \

CLIENT_SRCS = ./mandatory/client.c \
				./mandatory/utils.c \

SERVER_BONUS_SRCS = ./bonus/server_bonus.c \

CLIENT_BONUS_SRCS = ./bonus/client_bonus.c \
					./bonus/utils_bonus.c \

INCLUDE = ./mandatory/mini_talk.h ./libft/libft.h

INCLUDE_BONUS = ./bonus/mini_talk_bonus.h ./libft/libft.h

LIBFT = ./libft/libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJS_SERVER = $(SERVER_SRCS:.c=.o)

OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)


OBJS_SERVER_BONUS = $(SERVER_BONUS_SRCS:.c=.o)

OBJS_CLIENT_BONUS = $(CLIENT_BONUS_SRCS:.c=.o)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@


all : $(NAME) $(CLIENT)

$(NAME) : $(OBJS_SERVER) $(INCLUDE)
	make -C ./libft
	@$(CC) $(OBJS_SERVER) $(LIBFT) $(FLAGS) -o $(NAME)

$(CLIENT) : $(OBJS_CLIENT) $(INCLUDE)
	@$(CC) $(OBJS_CLIENT) $(LIBFT) $(FLAGS) -o $(CLIENT)
	@echo "mandatory part is ready"

$(SERVER_BONUS) : $(OBJS_SERVER_BONUS) 
	make -C ./libft
	@$(CC) $(OBJS_SERVER_BONUS) $(LIBFT) $(FLAGS) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(OBJS_CLIENT_BONUS) $(INCLUDE_BONUS)
	@$(CC) $(OBJS_CLIENT_BONUS) $(LIBFT) $(FLAGS) -o $(CLIENT_BONUS)
	@echo "bonus part is ready"

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

clean : 
	make clean -C ./libft
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	@echo "clean"


fclean : clean
	make fclean -C ./libft
	@rm -f $(NAME) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "fclean"

re : fclean all

bonusre : fclean bonus

.PHONY: all clean fclean re
