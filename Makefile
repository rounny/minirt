# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 04:12:14 by ccamie            #+#    #+#              #
#    Updated: 2022/07/14 11:09:20 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	minirt

CC			=	cc

CPPFLAGS	=	-I include
CPPFLAGS	+=	-Wall -Wextra -Werror

CPPFLAGS	+=	-O2

# CPPFLAGS	+=	-g

CFLAGS		=	-framework OpenGL -framework AppKit libmlx/libmlx.a

# CFLAGS		+=	-fsanitize=address
# CFLAGS		+=	-fsanitize=undefined

ECHO		=	@echo

MKDIR		=	@mkdir -p

RMDIR		=	@rm -rf
RM			=	@rm -f

HEADER		=	$(addprefix include/,	\
				bool.h					\
				data.h					\
				draw.h					\
				event.h					\
				key.h					\
				matrix.h				\
				minirt.h				\
				mlx.h					\
				mouse.h					\
				parser.h				\
				ray.h					\
				utils.h					\
				vec2.h					\
				vec3.h					\
				window.h				\
				)

FUNCTIONS	=	main.c					\
				minirt.c				\

FUNCTIONS	+=	$(addprefix draw/,		\
				$(addprefix sphere/,	\
				draw.c					\
				hit.c					\
				)						\
				axes.c					\
				draw.c					\
				find_object.c			\
				write.c					\
				)

FUNCTIONS	+=	$(addprefix event/,		\
				event.c					\
				key_down.c				\
				key_up.c				\
				mouse_down.c			\
				mouse_up.c				\
				terminate.c				\
				thread.c				\
				)

FUNCTIONS	+=	$(addprefix matrix/,	\
				column.c				\
				copy.c					\
				multiply.c				\
				new.c					\
				print.c					\
				rotate.c				\
				)

FUNCTIONS	+=	$(addprefix parser/,	\
				parser_main.c			\
				get_line_file.c			\
				check_file.c 			\
				check_elements.c		\
				ambient_lightning.c		\
				camera.c				\
				light.c					\
				utils_atof_atoi.c		\
				utils.c					\
				parser_color.c			\
				parser_vector.c			\
				sphere.c				\
				split_rt.c				\
				plane.c					\
				cylinder.c				\
				)

FUNCTIONS	+=	$(addprefix ray/,		\
				new.c					\
				position.c				\
				)						\

FUNCTIONS	+=	$(addprefix utils/,		\
				color_trim.c			\
				matrix_rotate.c			\
				matrix_scale.c			\
				maxf.c					\
				minf.c					\
				vec3_mulmat.c			\
				)

FUNCTIONS	+=	$(addprefix vec2/,		\
				add.c					\
				divide.c				\
				lenght.c				\
				new.c					\
				print.c					\
				subtract.c				\
				)

FUNCTIONS	+=	$(addprefix vec3/,		\
				add.c					\
				divide.c				\
				dot_product.c			\
				lenght.c				\
				map.c					\
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
				@make -C libmlx

object/%.o	:	source/%.c $(HEADER)
				@$(CC) $(CPPFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJECT)
				$(RMDIR) $(FOLDER)
				$(ECHO) "make \x1b[33mclean\x1b[0m"
				make clean -C libmlx

fclean		:
				$(RM) $(OBJECT)
				$(RMDIR) $(FOLDER)
				$(RM) $(NAME)
				$(ECHO) "make \x1b[33mfclean\x1b[0m"
				make clean -C libmlx

re			:	fclean all
