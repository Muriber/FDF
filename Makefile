# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 09:16:08 by bjimenez          #+#    #+#              #
#    Updated: 2022/08/29 11:35:20 by bjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= sources/main.c sources/fdf_errctrl.c sources/fdf_read_quad.c \
				sources/fdf_initvalues.c sources/fdf_utils.c sources/fdf_atoi_base.c \
				sources/fdf_coord_color_list.c sources/fdf_bresen.c sources/fdf_drawdata.c \
				sources/fdf_keyft.c sources/fdf_key_move_rot.c sources/fdf_extra_views.c \
				sources/fdf_color.c sources/fdf_views.c sources/fdf_menu_controls.c

OBJS		= ${SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

NAME		= sources/libfdf.a

RM			= rm -f

MINILIB_X	= -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

INCLUDE		= -I include

INCLUDE_A	= -L sources 

%.o: %.c
			$(CC) $(CFLAGS) -c $< $(INCLUDE) -o $@
			
all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n -> Procesando Norminette <-"
			@norminette sources/*.c
			@echo "\n -> Compilando MinilibX <-"
			@make -C minilibx_macos/ all --silent
			@echo "\n -> Compilando Libft <-"
			@make -C libft/ all --silent
			@echo "\n -> Configurando libft.a <-"
			@cp libft/libft.a $(NAME)
			@echo "\n -> Compilando libfdf <-"
			@ar rcs ${NAME} ${OBJS}
			@echo "\n -> Compilando FDF <-"
			@$(CC) $(CFLAGS) $(MINILIB_X) $(INCLUDE_A) -lfdf -L. -o fdf

bonus:		all

clean:		
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME}
			${RM} fdf
			make -C libft/ fclean
			make -C minilibx_macos/ clean
			
re:			fclean all

.PHONY:		all clean fclean re