CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/main.c src/read_map.c src/check_map.c src/free_handling.c src/error_handling.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -o so_long $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: re
	./so_long

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f so_long
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all run clean fclean re
