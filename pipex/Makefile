# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+      #
#   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#   Created: 2025/07/13 12:45:00 by mjeremy           #+#    #+#              #
#   Updated: 2025/07/13 12:45:00 by mjeremy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./inc -I./libft

# Source files
SRC_DIR = src
SRC = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils.c $(SRC_DIR)/exit_utils.c

# Object files
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Default target
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Link everything together
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "pipex compiled successfully"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Object files cleaned"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Everything cleaned"

# Recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
