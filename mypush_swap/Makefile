#
# makefile for libft functions
#

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

AR = ar
ARFLAGS = rcs

SRC_DIR = .
SRCS = $(SRC_DIR)/push_swap.c

SUBDIR = libft

.PHONY: all clean fclean re ${SUBDIR}

# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)

all:	$(NAME) $(SUBDIR)
	@echo  Featured compiler named $(NAME) has been compiled

$(NAME): $(OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(SUBDIR):
	$(MAKE) -C $(SUBDIR)

# Rule to compile object files from source files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "files Compiled .o generated"

clean:
	rm -rf ${OBJS} $(NAME)
	$(MAKE) -C $(SUBDIR) clean
	@echo "Cleaned up generated files"

fclean: clean
	$(RM) $(NAME)
# Rebuild the project from scratch
re: fclean all