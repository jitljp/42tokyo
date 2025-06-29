NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./src
INCLUDES_DIR = ./includes
LIBFT_DIR = ./libft

# Source files
SRCS = $(SRCS_DIR)/ft_printf.c \
		$(SRCS_DIR)/ft_printf_put.c \
		$(SRCS_DIR)/ft_printf_itoa_u.c \
		$(SRCS_DIR)/ft_printf_handle.c

# Object files
OBJS = $(SRCS:.c=.o)

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
