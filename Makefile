NAME		=	miniRT

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra #-fsanitize=address
#LDFLAGS		=	-L$(LIBFT_DIR) -L$(LIBFT_DIR) -framework OpenGL -framework Appkit
RM			=	rm -rf

# LIBFT_DIR	= ./libft/
#LIBMLX_DIR		= ./mlx/
# LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
#LIBMLX		= $(addprefix $(LIBMLX_DIR), libmlx.a)

HEAD		=	minirt.h
SRCS		=	main.c utils.c split_rt.c parser/parser_main.c parser/ambient_lightning.c parser/camera.c parser/light.c parser/utils_atof_atoi.c parser/parser_color.c parser/sphere.c parser/plane.c parser/cylinder.c
			

OBJS		=	$(SRCS:%.c=%.o)

.PHONY		:	all clean fclean re bonus

all			:	 $(NAME)

#libmlx:
#	@make -C $(LIBMLX_DIR)

# libmake:
# @make -C $(LIBFT_DIR)

$(NAME) 	:	$(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo ""
	@echo "\x1b[1;35m \x1b[1;35m ☆* Makefile is done SUCCESSFULLY! *☆\033[0m"
	@echo ""

%.o			:	%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
clean		:
	$(RM) $(OBJS)
# make clean -C ./libft
#	make clean -C ./mlx

fclean		:	clean
	$(RM) $(NAME)
# $(RM) $(LIBFT)

re : fclean all