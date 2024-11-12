# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 12:26:43 by afogonca          #+#    #+#              #
#    Updated: 2024/11/10 12:30:26 by afogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./libs/minilibx-linux -lm -Ilmlx -lXext -lX11 -g


LIBS = libs/mlx/libmlx.a libs/libft/libft.a

SRCS = srcs/main.c srcs/initial.c srcs/map_loader.c srcs/map_render.c \
		srcs/map_checker.c srcs/key_hook.c srcs/ft_free.c \
		srcs/player_mov.c srcs/map_checker2.c $(GNL)
NAME = so_long

all : deps $(NAME)

deps:
	$(MAKE) -C ./libs/mlx
	$(MAKE) -C ./libs/libft

$(NAME):
	$(CC) $(SRCS) $(LIBS) $(MLXFLAGS)
