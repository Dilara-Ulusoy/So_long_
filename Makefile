# Define variables
NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -Ilibft -Iprintf
MLXFLAGS = -L./minilibx-linux/ -lmlx -lXext -lX11
LIBFT_DIR = libft
LIBFT = libft/libft.a
PF_DIR = printf
PRINTF = printf/libftprintf.a
MLX_LIB = minilibx-linux/libmlx.a

GNL_DIR = gnl

# Source files and object files
SRC = so_long.c \
	check_and_exit.c \
      read_map.c \
      handle_key.c \
      load_image.c \
      check_map.c \
      check_map_1.c \
      init.c \
	  window.c \
      so_long_utils.c \
      gnl/get_next_line.c \
      gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Build executable
$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_LIB) $(MLXFLAGS) -o $(NAME)

# Rule to compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Build libft library
$(LIBFT):
	@$(MAKE) -C libft

# Build printf library
$(PRINTF):
	$(MAKE) -C printf

# Build MLX library
$(MLX_LIB):
	$(MAKE) -C minilibx-linux

# Clean object files and libraries
clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PF_DIR)

# Full clean (includes executable)
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PF_DIR)

# Rebuild the project
re: fclean all
