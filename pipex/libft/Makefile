NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = src
INCLUDES_DIR = .

# Source files by category
CHAR_SRCS = $(SRCS_DIR)/char/ft_isalnum.c \
			$(SRCS_DIR)/char/ft_isalpha.c \
			$(SRCS_DIR)/char/ft_isascii.c \
			$(SRCS_DIR)/char/ft_isdigit.c \
			$(SRCS_DIR)/char/ft_isprint.c \
			$(SRCS_DIR)/char/ft_tolower.c \
			$(SRCS_DIR)/char/ft_toupper.c

CONV_SRCS = $(SRCS_DIR)/conv/ft_atoi.c \
			$(SRCS_DIR)/conv/ft_itoa.c

GNL_SRCS = $(SRCS_DIR)/gnl/get_next_line.c \

IO_SRCS = $(SRCS_DIR)/io/ft_putchar_fd.c \
		  $(SRCS_DIR)/io/ft_putendl_fd.c \
		  $(SRCS_DIR)/io/ft_putnbr_fd.c \
		  $(SRCS_DIR)/io/ft_putstr_fd.c

LST_SRCS = $(SRCS_DIR)/lst/ft_lstadd_back.c \
		   $(SRCS_DIR)/lst/ft_lstadd_front.c \
		   $(SRCS_DIR)/lst/ft_lstclear.c \
		   $(SRCS_DIR)/lst/ft_lstdelone.c \
		   $(SRCS_DIR)/lst/ft_lstiter.c \
		   $(SRCS_DIR)/lst/ft_lstlast.c \
		   $(SRCS_DIR)/lst/ft_lstmap.c \
		   $(SRCS_DIR)/lst/ft_lstnew.c \
		   $(SRCS_DIR)/lst/ft_lstsize.c

MEM_SRCS = $(SRCS_DIR)/mem/ft_bzero.c \
		   $(SRCS_DIR)/mem/ft_calloc.c \
		   $(SRCS_DIR)/mem/ft_memchr.c \
		   $(SRCS_DIR)/mem/ft_memcmp.c \
		   $(SRCS_DIR)/mem/ft_memcpy.c \
		   $(SRCS_DIR)/mem/ft_memmove.c \
		   $(SRCS_DIR)/mem/ft_memset.c

PRINTF_SRCS = $(SRCS_DIR)/printf/ft_printf.c \
			  $(SRCS_DIR)/printf/ft_printf_handle.c \
			  $(SRCS_DIR)/printf/ft_printf_itoa_u.c \
			  $(SRCS_DIR)/printf/ft_printf_put.c

STR_SRCS = $(SRCS_DIR)/str/ft_split.c \
		   $(SRCS_DIR)/str/ft_strchr.c \
		   $(SRCS_DIR)/str/ft_strdup.c \
		   $(SRCS_DIR)/str/ft_striteri.c \
		   $(SRCS_DIR)/str/ft_strjoin.c \
		   $(SRCS_DIR)/str/ft_strlcat.c \
		   $(SRCS_DIR)/str/ft_strlcpy.c \
		   $(SRCS_DIR)/str/ft_strlen.c \
		   $(SRCS_DIR)/str/ft_strmapi.c \
		   $(SRCS_DIR)/str/ft_strncmp.c \
		   $(SRCS_DIR)/str/ft_strnstr.c \
		   $(SRCS_DIR)/str/ft_strrchr.c \
		   $(SRCS_DIR)/str/ft_strtrim.c \
		   $(SRCS_DIR)/str/ft_substr.c

# All source files
SRCS = $(CHAR_SRCS) $(CONV_SRCS) $(GNL_SRCS) $(IO_SRCS) $(LST_SRCS) $(MEM_SRCS) $(PRINTF_SRCS) $(STR_SRCS)

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
