# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 12:44:14 by fhenckel          #+#    #+#              #
#    Updated: 2024/11/08 12:44:09 by fhenckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# makefile for libft functions
#

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

AR = ar
ARFLAGS = rcs

SRC_DIR = .
#SRCS = $(shell ls $(SRC_DIR)/*.c | grep -v "bonus.c")
SRCS = $(shell ls $(SRC_DIR)/*.c)

BSRCS = $(shell ls $(SRC_DIR)/*bonus.c)

.PHONY: all clean fclean re

#OBJS = $(SRCS:.c=.o)
# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)
BOBJS = $(BSRCS:$(SRC_DIR)/%.c=%.o)

all:	$(NAME)
	@echo  Featured compiler named $(NAME) has been compiled


$(NAME): $(OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Rule to compile object files from source files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "files Compiled .o generated"

bonus: $(BOBJS) 
	$(AR) $(ARFLAGS) $(NAME) $(BOBJS)

so:
	$(CC) -nostartfiles -shared -o libft.so $(OBJS)

clean:
	@rm -rf *.o $(NAME)
	@echo "Cleaned up generated files"
fclean: clean
	$(RM) $(NAME)
# Rebuild the project from scratch
re: fclean all
