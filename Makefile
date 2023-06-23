NAME		=	printf
CC		=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
LIBFT		=	lib

all: libft $(NAME)

libft:
	make -C $(LIBFT)

$(NAME):
	$(CC) $(CFLAGS) main.c ft_printf.c -I$(LIBFT)/header

.PHONY: all libft
