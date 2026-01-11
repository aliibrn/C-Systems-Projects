# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbouram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 17:06:16 by abbouram          #+#    #+#              #
#    Updated: 2024/07/25 17:06:18 by abbouram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
 
SRCS =  philo.c \
		lunch_the_dinner.c \
		monitor.c \
		./utils/check_numbers.c \
		./utils/linked_list.c \
		./utils/linked_list1.c \
		./utils/utils.c \
		./utils/init.c \
		./utils/helper_functions.c \

CFLAGS = -Wall -Wextra -g3 -fsanitize=address

GCC = cc

OBJS = $(SRCS:.c=.o)

INCLUDE =  ./philo.h 

.c.o:
	@$(GCC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)  
	@$(GCC) $(CFLAGS) $(OBJS) -o $(NAME) 
	@echo "done"

all: $(NAME) 

clean:
	@rm -f $(OBJS)
	 
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
