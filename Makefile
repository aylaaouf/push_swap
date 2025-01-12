CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = algo/algo.c parsing/valid_input.c utils/operations.c utils/operations2.c utils/operations3.c utils/helpers.c main.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft.a
LIBFTD = libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTD)
	cp $(LIBFTD)/$(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFTD) -l ft -o $(NAME)

clean:
	make -C $(LIBFTD) fclean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFTD) fclean
	rm -f push_swap

re: fclean all
