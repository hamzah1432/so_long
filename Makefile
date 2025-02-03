CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = main.c get_next_line.c get_next_line_utils.c ft_split.c read_map.c check_map.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(OBJ) -o so_long $(MLX_FLAGS)

# all: $(OBJ)
# 	$(CC) $(OBJ) -o so_long 

%.o: %.c
	$(CC)  -c $< -o $@

run: re
	./so_long

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f so_long

re: fclean all

.PHONY: all run clean fclean re
