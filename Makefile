CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = knight

SRC = src/main.c src/read_map.c src/check_map.c src/free_handling.c src/error_handling.c src/check_valid_path.c src/initial.c src/start_menu.c
OBJ = $(SRC:.c=.o)
OBJ_DIR = obj
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ)))

# Default target to build the executable
all: $(NAME)

$(NAME): $(OBJ_PATH) $(LIBFT)
	$(CC) $(OBJ_PATH) -o knight $(MLX_FLAGS) -L$(LIBFT_DIR) -lft
# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Rule to compile .c files to .o
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)  # Make sure the object directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and libft build
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Clean everything including executable and libft
fclean: clean
	rm -rf knight
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

