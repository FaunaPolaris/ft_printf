NAME		=	printf

CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror

SRC_FILES	=	fp_putchar_fd.c fp_putnbr_and_len.c fp_putnbr_base.c fp_putpointer.c fp_putstr_and_len.c
SRC_FILES	:=	$(addprefix utils/, $(SRC_FILES))
BONUS_SRC	=	fp_atoi.c fp_isdigit.c fp_itoa.c fp_plen.c fp_printf_flags_bonus.c fp_strlen.c fp_strnstr.c fp_isalpha.c 
BONUS_SRC	+=	fp_itoa_base.c fp_memcpy.c fp_printf_flags_bonus2.c fp_strchr.c fp_strndup.c ft_printf_error_bonus.c
BONUS_SRC	:=	$(addprefix bonus/, $(BONUS_SRC))


INCLUDE		=	-Iheader/

TEST_MAIN	=	main.c
PRINTF		=	ft_printf.c
BONUS		=	ft_printf_bonus.c

all: $(NAME)

$(NAME):
	@$(CC) $(C_FLAGS) $(SRC_FILES) $(BONUS_SRC) $(PRINTF) $(BONUS) $(TEST_MAIN) $(INCLUDE) -o $(NAME)

fclean:
	@rm $(NAME)

re: fclean all

.PHONNY: all fclean re

