# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 12:44:14 by fhenckel          #+#    #+#              #
#    Updated: 2024/11/05 17:22:01 by fhenckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# makefile for libft functions
#

NAME = ft

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

SRC_DIR = .
SRCS = $(shell ls $(SRC_DIR)/*.c)

INCLUDES = -I.

.PHONY: all clean fclean re

#OBJS = $(SRCS:.c=.o)
# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=obj/%.o)

all:	$(NAME)
	@echo  Featured compiler named libft.a has been compiled


$(NAME): $(OBJS) 
#$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
	$(AR) $(ARFLAGS) lib$(NAME).a $(OBJS)

# Rule to compile object files from source files
obj/%.o: $(SRC_DIR)/%.c | obj
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "files Compiled"

# Create the obj/ directory if it does not exist
obj:
	@mkdir -p obj
	@echo "obj dir created"
#
#TO BE DELETE BEFORE SUBMIT
#
so:
	$(CC) -nostartfiles -shared -o libft.so $(OBJS)

clean:
	@rm -rf obj lib$(NAME).a
	@echo "Cleaned up generated files"
fclean: clean
	$(RM) $(NAME)
# Rebuild the project from scratch
re: fclean all
