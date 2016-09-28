# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchicote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 15:05:38 by cchicote          #+#    #+#              #
#    Updated: 2016/09/12 15:05:39 by cchicote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INCLUDES = -I./libft/ -I./minilibx/ -I./includes/ -I./minilibxLinux/

CFLAGS = -Wall -Werror -Wextra $(INCLUDES) #-Werror

MLXOSX = -lmlx -framework OpenGL -framework AppKit

LXLIBMLX = -L ./minilibxLinux/ -lmlx

MLXLINUX = -L/usr/X11/lib -lXext -lX11 -lm

LIBFT = -L ./libft/ -lft

PATH_SRC = src/

SRC = main.c \
		draw.c \
		manage_key.c \
		manage_colors.c \
		manage_mouse.c \
		change_fract.c \

SRCO = $(patsubst %.c, %.o,$(addprefix $(PATH_SRC), $(SRC)))

all: osx

libft:
	@make -C libft

linux: libft $(SRCO)
	@make -C minilibxLinux/
	@gcc $(CFLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(LXLIBMLX) $(MLXLINUX) -lm
	@echo "\033[32;40m\ncompilation OK\n\033[0;0m"

osx: libft $(SRCO)
	@gcc $(CFLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(MLXOSX)
	@echo "\033[32;40m\ncompilation OK\n\033[0;0m"

.PHONY: clean fclean osx libft re all linux

clean:
	@make -C libft/ clean
	@/bin/rm -f $(SRCO)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

relinux: fclean linux

re: fclean all
