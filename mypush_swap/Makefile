#
# makefile for libft functions
#

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.


SRC_DIR = .
SRCS = $(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/push_swap_utils.c \
	$(SRC_DIR)/push_rules.c \

#libft
LIBFT_DIR = libft/
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft
LIBFT_LIB = $(LIBFT_DIR)libft.a

.PHONY: all clean fclean re ${SUBDIR}

# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)

all: subsytems	$(NAME) 
	@echo  Featured compiler named $(NAME) has been compiled

subsytems:
	@make -C $(LIBFT_DIR) all

$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(CCFLAGS) $(LIBFT_FLAGS) -o $(NAME) 


# Rule to compile object files from source files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "files Compiled .o generated"

clean: 
	@make -C $(LIBFT_DIR) clean
	rm -rf ${OBJS}
	@echo "Cleaned up generated files"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) -f $(NAME)
	@echo removed $(NAME)
# Rebuild the project from scratch
re: fclean all