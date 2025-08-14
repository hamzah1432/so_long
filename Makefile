CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =
NAME = knight

# Libraries
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

# Source files
SRC = src/main.c src/read_map.c src/check_map.c src/free_handling.c \
      src/error_handling.c src/check_valid_path.c src/initial.c src/start_menu.c
OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

# Build executable
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

# Compile source files to obj directory
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re