CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c algo/algo.c algo/algo2.c algo/small_algo.c algo/small_algo_helpers.c algo/algo_helpers.c parsing/valid_input.c parsing/valid_input_helper.c utils/operations.c utils/operations2.c utils/operations3.c utils/helpers.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft.a
LIBFTD = libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTD)
	cp $(LIBFTD)/$(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFTD) -l ft -o $(NAME)

bonus:
clean:
	make -C $(LIBFTD) fclean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFTD) fclean
	rm -f push_swap

re: fclean all
