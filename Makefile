NAME		=	printf
CC		=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
LIBFT		=	lib
YELLOW		=	\033[0;93m
SET_0		=	\033[0m

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME):
	@$(CC) $(CFLAGS) main.c ft_printf* -I$(LIBFT)/header -Iheader -L$(LIBFT) -lft -o $(NAME)
	@echo "$(YELLOW)compilation succes!$(SET_0)"

clean:
	@make -C $(LIBFT) fclean
	@echo "$(YELLOW)clean complete$(SET_0)"

fclean: clean
	@rm printf

re: fclean all

.PHONY: all libft clean fclean re
