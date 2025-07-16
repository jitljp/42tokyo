# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeremy <jeremy@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 18:15:00 by jeremy            #+#    #+#              #
#    Updated: 2025/07/15 18:15:00 by jeremy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = pipex
CC         = cc
CFLAGS     = -Wall -Wextra -Werror
INCLUDES   = -I inc -I libft

LIBFT_DIR  = libft
LIBFT_LIB  = $(LIBFT_DIR)/libft.a

SRCS       = src/pipex.c  src/exit_utils.c src/utils.c
OBJS       = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	cd $(LIBFT_DIR) && make

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re