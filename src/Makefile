CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft
LDFLAGS = -L../libft -lft
SRC = swap_operations.c push_operations.c rotate_operations.c main.c rrotate_operations.c parsing.c parsing_utils.c quicksort.c algorithm.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS )$(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
