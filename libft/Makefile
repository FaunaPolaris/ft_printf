NAME		=	libft.a

AR		=	ar rc
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRC_FILES	=	fp_atoi.c fp_isalpha.c fp_isdigit.c fp_itoa_base.c
SRC_FILES	+=	fp_itoa.c fp_leftrightj.c fp_memcpy.c fp_plen.c
SRC_FILES	+=	fp_putchar_fd.c fp_putnbr_and_len.c fp_putnbr_base.c
SRC_FILES	+=	fp_putpointer.c fp_putstr_and_len.c fp_strchr.c
SRC_FILES	+=	fp_strlen.c fp_strndup.c fp_strnstr.c

OBJS_DIR	=	objs
SRC_OBJS	=	$(addprefix $(OBJS_DIR)/,$(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME):$(SRC_OBJS)
	@$(AR) $(NAME) $(SRC_OBJS)

$(OBJS_DIR)/%.o:.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
