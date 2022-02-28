NAME =		so_long

SRCS =		srcs/get_next_line.c srcs/utils.c srcs/main.c srcs/utils2.c srcs/parsing1.c \
		srcs/parsing2.c srcs/init_window.c  srcs/init_window2.c srcs/move_player.c \
		srcs/ft_printf.c  srcs/ft_printf_fct.c  srcs/ft_printf_hexa.c \
		srcs/ft_printf_ptr.c  srcs/ft_printf_unsigned.c

_DEPS =		so_long.h

INCL =		./includes/

DEPS =		$(patsubst %,$(INCL)/%,$(_DEPS))

OBJS =		${SRCS:.c=.o}

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g

MLX =		./minilibx

MLX_LIB = 	./minilibx/libmlx_Linux.a

.c.o:		${DEPS}
		${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS}  ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(MLX_LIB):
		make -C ${MLX} -j


all:		${NAME}

clean:		
		${RM} ${OBJS}
		make clean -C ${MLX}

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME} ${MLX_LIB}

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re

#-framework OpenGL -framework AppKit
