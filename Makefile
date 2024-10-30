NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft

RM = rm -f

SRCS = algo.c algo_helper.c operations.c push_swap.c stack_utils.c utils.c errors_handling.c

OBJS = ${SRCS:.c=.o}

LIBPATH	= libft/

all: $(NAME)

${NAME}: ${OBJS}
	 make -C ${LIBPATH}
	 ${CC} ${CFLAGS} $^ ${LIB} -o $@

clean:
	make clean -C ${LIBPATH}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBPATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
