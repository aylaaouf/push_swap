CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = valid_input.c main.c helpers.c operations.c algo.c
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
	make -C $(LIBFTD) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFTD) fclean
	rm -f push_swap

re: fclean all
