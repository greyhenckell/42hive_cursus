# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 12:44:14 by fhenckel          #+#    #+#              #
#    Updated: 2024/11/14 19:03:55 by fhenckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# makefile for libft functions
#

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

AR = ar
ARFLAGS = rcs

SRC_DIR = .
SRCS = $(SRC_DIR)/ft_helpers.c $(SRC_DIR)/ft_printf.c  $(SRC_DIR)/ft_utils.c

.PHONY: all clean fclean re

# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)

all:	$(NAME)
	@echo  Featured compiler named $(NAME) has been compiled

$(NAME): $(OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Rule to compile object files from source files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "files Compiled .o generated"

clean:
	@rm -rf *.o $(NAME)
	@echo "Cleaned up generated files"

fclean: clean
	$(RM) $(NAME)
# Rebuild the project from scratch
re: fclean all
