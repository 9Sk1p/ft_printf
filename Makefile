NAME = "libftftprintf.h"
SRCS = ft_print.c \
			ft_print_chars.c \
			ft_print_hex.c \
			ft_print_numbers.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)
all:
