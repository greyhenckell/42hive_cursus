#
# makefile for libft functions
#

NAME = so_long.a

CC = cc
CCFLAGS := -Wall -Wextra -Werror -Iheaders/

INCLUDES = -I.

AR = ar
ARFLAGS = rcs

SRC_DIR = .
SRCS = $(SRC_DIR)/main.c
GNL_SRC = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)
PRINTF_SRC =  $(addprefix printf/, ft_helpers.c ft_printf.c ft_utils.c)
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := ml-linux/

SUBDIR = libft

.PHONY: all clean fclean re ${SUBDIR}

# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

all:	$(NAME)
	@echo  Featured compiler named $(NAME) has been compiled

$(NAME): $(OBJS) $(GNL_OBJ) $(PRINTF_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $^
	$(CC) $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


# Rule to compile object files from source files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) -Imlx -Iheaders -c $< -o $@
	@echo "files Compiled .o generated"

clean:
	@rm -rf ${OBJS} $(GNL_OBJ) $(PRINTF_OBJ)
	@echo "Cleaned up generated files"

fclean: clean
	make clean -C mlx/
	$(RM) -f $(NAME)
# Rebuild the project from scratch
re: fclean all