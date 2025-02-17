NAME    =       push_swap

SRCS    =       push_swap.c \
		initial_parsing.c \
		struct_init.c \
		sort_stack.c \
		sort_utils.c \
		init_nodes_stack_a.c \
		init_nodes_stack_b.c \
		lst_utils.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		error_cleanup.c

OBJS            = ${SRCS:.c=.o}
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror #-g3 -fsanitize=address,leak
RM              = rm -f

all:		${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:         all clean fclean re
