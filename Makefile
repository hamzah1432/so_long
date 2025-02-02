CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = main.c get_next_line.c get_next_line_utils.c ft_split.c read_map.c
OBJ = $(SRC:.c=.o)

# all: $(OBJ)
# 	$(CC) $(OBJ) -o my_program $(MLX_FLAGS)

all: $(OBJ)
	$(CC) $(OBJ) -o my_program 

%.o: %.c
	$(CC)  -c $< -o $@

run: all
	./my_program

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f my_program

re: fclean all
