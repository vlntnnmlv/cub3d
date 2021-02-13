# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 12:56:59 by rmarguri          #+#    #+#              #
#    Updated: 2020/10/28 13:22:00 by rmarguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c cub3d.c ./config/config.c ./config/get_next_line.c ./config/get_next_line_utils.c \
./config/map.c ./config/convertmap.c ./config/sprites.c ./config/get.c ./config/parse.c ./config/utils.c \
./engine/ray.c ./engine/image.c ./engine/utils1.c ./engine/utils2.c ./engine/utils3.c \
./engine/draw_walls.c ./engine/draw_sprites.c \
./engine/minimap.c ./engine/color.c \
./manager/close_window.c \
./controls/controller.c ./controls/move.c ./controls/rotate.c \
./bmp/bmp.c

OBJS = $(SRCS:.c=.o)

CC = clang
RM = rm -f
CFLAGS = -O3 -Wall -Wextra -Werror -I.
LIBS = -lmlx -framework OpenGL -framework AppKit -lm libft.a libmlx.dylib
MLX = libmlx.dylib
LIBFT = libft.a

NAME = cub3D

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
	@$(MAKE) -C mlx_mms
	@mv mlx_mms/$(MLX) .

$(LIBFT):
	@$(MAKE) -C libft
	@mv libft/$(LIBFT) .

go:
	@$(MAKE) clean
	@./$(NAME) map.cub

norm:
	@norminette  ./libft/* ./bmp/* ./config/* ./controls/* \
	./engine/* ./manager/* cub3d.c main.c cub3d.h types.h

clean:
	@$(MAKE) -C mlx_mms clean
	@$(MAKE) -C libft clean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) $(MLX) $(LIBFT)

re: fclean $(NAME)

.PHONY:	all clean fclean re go norm