NAME = push_swap 

NAME_BONUS = checker

SRCS =  push_swap.c \
		check_format.c \
		fill_nodes.c \
		utils.c \
		./linked_list/linked_list.c \
		./moves/push.c \
		./moves/reverse_rotate.c \
		./moves/rotate.c \
		./moves/swap.c \
		./linked_list/utils_index.c \
		./linked_list/utils_index2.c \
		./sorting_algo/mini_sort.c \
		./sorting_algo/big_sort.c \

BONUS_SRCS = ./bonus/checker_bonus.c \
			./bonus/moves_checker_bonus/rotate_checker_bonus.c \
			./bonus/moves_checker_bonus/push_checker_bonus.c \
			./bonus/moves_checker_bonus/reverse_rotate_checker_bonus.c \
			./bonus/moves_checker_bonus/swap_checker_bonus.c \
			./linked_list/linked_list.c \
			utils.c \
			check_format.c \
			fill_nodes.c \

FLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT = ./libft/

GCC = cc

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS_SRCS:.c=.o)

INCLUDE = push_swap.h ./libft/libft.h 

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)  
	@make -C $(LIBFT)
	@$(GCC) $(OBJS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME)
	@echo "\033[1;32mPUSH SWAP Compiled\033[0m"


all: $(NAME) 

$(NAME_BONUS) : $(INCLUDE) $(OBJS_BONUS)
	@make -C $(LIBFT)
	@$(GCC) $(OBJS_BONUS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME_BONUS)
	@echo "\033[1;32mBONUS Compiled\033[0m"

bonus : $(NAME_BONUS)

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "clean"
	@echo "\033[1;32mclean\033[0m"
	 
fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "\033[1;32mfclean\033[0m"

re: fclean all

bonus_re : fclean bonus

.PHONY: all clean fclean re