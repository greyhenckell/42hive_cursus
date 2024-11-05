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

LIB_NAME = ft

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.c)

INCLUDES = -I.

#OBJS = $(SRCS:.c=.o)
# Generate corresponding .o object files for each .c file
OBJS = $(SRCS:$(SRC_DIR)/%.c=obj/%.o)

# define the executable file 
MAIN = mout

all:	$(MAIN)
	@echo  Featured compiler named libft.a has been compiled


$(MAIN): $(OBJS) 
#$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
	$(AR) $(ARFLAGS) lib$(LIB_NAME).a $(OBJS)

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
	@rm -rf obj lib$(LIB_NAME).a
	@echo "Cleaned up generated files"

# Rebuild the project from scratch
re: fclean all
