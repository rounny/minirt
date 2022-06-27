# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 04:12:14 by ccamie            #+#    #+#              #
#    Updated: 2022/06/27 13:32:12 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	minirt

CC			=	cc

CPPFLAGS	=	-I .
CPPFLAGS	+=	-Wall -Wextra -Werror

CPPFLAGS	+=	-g

CFLAGS		=	-framework OpenGL -framework AppKit libmlx/libmlx.a

CFLAGS		+=	-fsanitize=address
CFLAGS		+=	-fsanitize=undefined

ECHO		=	@echo

MKDIR		=	@mkdir -p

RMDIR		=	@rm -rf
RM			=	@rm -f

HEADER		=	draw.h					\
				minirt.h				\
				mlx.h					\
				vec3.h					\
				vec2.h					\

FUNCTIONS	=	main.c					\
				utils.c					\
				split_rt.c				\
				launch_window.c			\
				vec2_new.c				\

FUNCTIONS	+= 	$(addprefix parser/,	\
				parser_main.c			\
				ambient_lightning.c		\
				camera.c				\
				light.c					\
				utils_atof_atoi.c		\
				parser_color.c			\
				sphere.c				\
				plane.c					\
				cylinder.c				\
				)

FUNCTIONS	+=	$(addprefix draw/,		\
				draw.c					\
				reflect.c				\
				sphere.c				\
				write.c					\
				)

FUNCTIONS	+=	$(addprefix utils/,		\
				matrix_rotate.c			\
				maxf.c					\
				terminate.c				\
				vec3_mulmat.c			\
				)

FUNCTIONS	+=	$(addprefix vec3/,		\
				add.c					\
				dot_product.c			\
				lenght.c				\
				multiply.c				\
				new.c					\
				normalize.c				\
				print.c					\
				subtract.c				\
				)

SOURCE		=	$(addprefix source/, $(FUNCTIONS))
OBJECT		=	$(addprefix object/, $(FUNCTIONS:.c=.o))
FOLDER		=	$(sort $(dir object/ $(OBJECT)))

.SUFFIXES	:
.SUFFIXES	:	.c .o

.PHONY		:	all clean fclean re libmlx

all			:	libmlx $(FOLDER) $(NAME)

$(NAME)		:	$(OBJECT)
				@$(CC) $(CFLAGS) $(OBJECT) -o $(NAME)
				$(ECHO) "make \x1b[32mdone\x1b[0m"

$(FOLDER)	:
				$(MKDIR) $@

libmlx	:
				make -C libmlx

object/%.o	:	%.c $(HEADER)
				@$(CC) $(CPPFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJECT)
				$(RMDIR) $(FOLDER)
				$(ECHO) "make \x1b[33mclean\x1b[0m"

fclean		:
				$(RM) $(OBJECT)
				$(RMDIR) $(FOLDER)
				$(RM) $(NAME)
				$(ECHO) "make \x1b[33mfclean\x1b[0m"

re			:	fclean all
