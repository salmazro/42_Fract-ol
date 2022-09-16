NAME		=	fractol
LIBX_DIR	=	minilibx
LIBX		=	$(LIBX_DIR)/libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS 		= srcs/main.c srcs/keyHook.c srcs/math_utils.c srcs/helper.c srcs/helper1.c srcs/helper2.c srcs/error_utils.c
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

%.o : %.
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	@export CFLAGS='-Wno-deprecated-declarations'; ${MAKE} -sC $(LIBX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME) $(LIBX)

all : $(NAME)

clean:
	rm -rf ${OBJS}

fclean: clean
	${MAKE} -sC $(LIBX_DIR) clean
	rm -rf ${NAME} fract-ol

re: fclean all

