#
# makefile for libft functions
#

NAME = so_long

CC = cc
CCFLAGS := -Wall -Wextra -Werror -I/usr/include -Iheaders -Imlx

MLX_FLAGS = -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz


SRC_DIR = .
GNL_DIR = get_next_line/
PRINTF_DIR = ./printf
MLX_DIR = mlx/
LIBFT_DIR = libft/

LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

MLX_LIB = $(MLX_DIR)libmlx_Linux.a
LIBFT_LIB = $(LIBFT_DIR)libft.a


.PHONY: all clean fclean re

G = "\033[32m"
X = "\033[0m"

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/read_map.c \
		$(SRC_DIR)/game_setup.c \
		


# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)


all: subsytems $(NAME)
	@echo  Featured compiler named $(NAME) has been compiled

subsytems:
	@make -C $(MLX_DIR) all
	@make -C $(LIBFT_DIR) all

$(NAME):  $(OBJS) 
	@echo $(G)Finished [$(SRCS)]$(X)
	$(CC) $(OBJS) $(CCFLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME) 

# Rule to compile object files from source files
%.o: %.c
	$(CC) $(CCFLAGS) -g3 -c $< -o $@ 
	@echo "files Compiled"

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@rm -rf ${OBJS}
	@echo "Cleaned up generated files"

fclean: clean
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) -f $(NAME)
	@echo removed $(NAME)

	
# Rebuild the project from scratch
re: fclean all