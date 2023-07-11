NAME		=	libftprintfi.a

AR		=	ar -rcT
CC		=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror

LIBFT		=	libft/libft.a
YELLOW		=	\033[0;93m
SET_0		=	\033[0m

SRC_FILES	=	ft_printf.c

SRC_BONUS	=	ft_printf_bonus.c ft_printf_flags_bonus.c ft_printf_flag_bonus2.c
SRC_BONUS	+=	ft_printf_error_bonus.c

OBJS_DIR	=	objs
SRC_OBJ		=	$(addprefix $(OBJS_DIR)/,$(SRC_FILES:.c=.o))
BONUS_OBJ	=	$(addprefix $(OBJS_DIR)/,$(SRC_BONUS:.c=.o))

all: libft $(NAME)

libft:
	@make -C libft

$(NAME): $(OBJ_SRC)
	@$(AR) $(NAME) $(SRC_OBJ) 
	@echo "$(YELLOW)compilation succes!$(SET_0)"

bonus: $(BONUS_OBJ)
	@$(AR) $(NAME) $(SRC_OBJS) $(LIBFT)
	@echo "$(YELLOW)bonus compiled!$(SET_0)"

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ -Iheader/

clean:
	@make -C $(LIBFT) fclean
	@echo "$(YELLOW)clean complete$(SET_0)"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all libft bonus clean fclean re
