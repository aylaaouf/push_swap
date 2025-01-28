CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c main_utils.c algo/algo.c algo/algo2.c algo/small_algo.c algo/small_algo_helpers.c algo/algo_helpers.c parsing/valid_input.c parsing/valid_input_helper.c utils/operations.c utils/operations2.c utils/operations3.c utils/helpers.c
SRCS_BONUS = bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c parsing/valid_input.c parsing/valid_input_helper.c utils/helpers.c main_utils.c utils/operations.c utils/operations2.c utils/operations3.c bonus/bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = push_swap
NAME_BONUS = checker
LIBFT = libft.a
LIBFTD = libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTD)
	cp $(LIBFTD)/$(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFTD) -l ft -o $(NAME)

bonus: $(OBJS_BONUS)
	make -C $(LIBFTD)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L $(LIBFTD) -l ft -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFTD) fclean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFTD) fclean
	rm -f push_swap checker

re: fclean all
