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
MLXFLAGS = -L ./libs/minilibx-linux -lm -Ilmlx -lXext -lX11
RM = rm -f

LIBS = libs/mlx/libmlx.a libs/libft/libft.a

OBJS = $(SRCS:.c=.o)
SRCS = srcs/main.c srcs/initial.c srcs/map_loader.c srcs/map_render.c	\
		srcs/map_checker.c srcs/key_hook.c srcs/ft_free.c				\
		srcs/player_mov.c srcs/map_checker2.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_SRCS = srcs_bonus/main.c srcs_bonus/initial.c srcs_bonus/map_loader.c		\
		srcs_bonus/map_render.c srcs_bonus/map_checker.c srcs_bonus/key_hook.c	\
		srcs_bonus/ft_free.c srcs_bonus/player_mov.c srcs_bonus/map_checker2.c


NAME = so_long
BONUS_NAME = so_long_bonus

all: deps $(NAME)

deps:
	$(MAKE) -C ./libs/mlx/
	$(MAKE) -C ./libs/libft/

bonus: deps $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) $(MLXFLAGS) -o $(BONUS_NAME)

clean:
	$(MAKE) clean -C ./libs/libft/
	$(MAKE) clean -C ./libs/libft/
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libs/libft/
	$(MAKE) fclean -C ./libs/libft/
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

gdb: deps
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) $(MLXFLAGS) -g

gdbbonus: deps
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBS) $(MLXFLAGS) -g

re: fclean all
