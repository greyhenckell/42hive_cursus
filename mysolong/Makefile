#
# makefile for libft functions
#

NAME = solong

CC = cc
CCFLAGS := -Wall -Wextra -Werror -Iheaders -Imlx

MLX_FLAGS = -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRC_DIR = .
GNL_DIR = ./get_next_line
PRINTF_DIR = ./printf
MLX_DIR = ./mlx
LIBFT_DIR = ./libft


MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

.PHONY: all clean fclean re

SRCS = $(SRC_DIR)/main.c \
		$(GNL_DIR)/get_next_line.c \
       $(GNL_DIR)/get_next_line_utils.c \
	   $(PRINTF_DIR)/ft_helpers.c \
	   $(PRINTF_DIR)/ft_printf.c \
	   $(PRINTF_DIR)/ft_utils.c \
	   $(LIBFT_DIR)/ft_strlen.c \
	   $(LIBFT_DIR)/ft_strchr.c

# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)


all: $(NAME)
	@echo  Featured compiler named $(NAME) has been compiled

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(OBJS) $(CCFLAGS) -o $(NAME)  $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

# Rule to compile object files from source files
%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<
	@echo "files Compiled"

clean:
	@rm -rf ${OBJS}
	@make clean -C $(MLX_DIR)
	@echo "Cleaned up generated files"

fclean: clean
	$(RM) -f $(NAME)
	make fclean -C $(MLX_DIR)
	
# Rebuild the project from scratch
re: fclean all