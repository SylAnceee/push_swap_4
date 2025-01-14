NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
SRC		=	combo.c \
			ft_find.c \
			ft_functions.c \
			main.c \
			operations.c \
			stack_utils_2.c \
			stack_utils.c \
			split.c \

SRC_PATH = ./src/
OBJ_PATH = ./bin/

RM = rm -rf

OBJ		=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))
DEPS	=	$(OBJ:.o=.d)

all		=	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
		mkdir -p $(dir $@)
		@ $(CC) $(CFLAGS) -c $< -o $@

clean	:
	${RM} ${OBJ_PATH} ${DEPS}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all
.PHONY	:	all clean fclean re

-include $(DEPS)