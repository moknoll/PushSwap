CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft
LDFLAGS = -L../libft -lft
MAKEFLAGS += --silent
SRC = swap_operations.c push_operations.c rotate_operations.c main.c rrotate_operations.c parsing.c parsing_utils.c algorithm.c set_nodes.c sort_nodes.c sort_small.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

# Farben definieren
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@figlet "Push Swap"
	@echo "$(YELLOW)Building: [#.........]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [##........]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [###.......]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [####......]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [######....]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [#######...]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [########..]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [#########.]$(RESET)\r"
	@sleep 0.2
	@echo "$(YELLOW)Building: [##########]$(RESET)\r\n"
	@$(CC) $(CFLAGS )$(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN) ✅ Build Complete! $(Reset)"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
