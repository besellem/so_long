# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 20:27:25 by besellem          #+#    #+#              #
#    Updated: 2021/03/14 00:59:17 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Constants
MUTE		=	
NAME		=	cub3D
BMP_FILE	=	./saved.bmp

## Sources
INCS		=	-I incs -Llibft -lft -Ilibft/incs
MLIBX		=	libmlx.dylib

# Paths
PATH_SRCS	:=	./srcs

PATH_OTHERS	:=	__others__
PATH_BONUS	:=	bonus
PATH_COMMON	:=	common
PATH_ENGINE	:=	engine
PATH_EVENTS	:=	events
PATH_PARSER	:=	parser

SRCS		=	$(PATH_SRCS)/$(PATH_OTHERS)/save.c \
				$(PATH_SRCS)/$(PATH_OTHERS)/utils.c \
				$(PATH_SRCS)/$(PATH_BONUS)/gun_bonus.c \
				$(PATH_SRCS)/$(PATH_BONUS)/init_bonus.c \
				$(PATH_SRCS)/$(PATH_BONUS)/life_bar_bonus.c \
				$(PATH_SRCS)/$(PATH_BONUS)/minimap_bonus.c \
				$(PATH_SRCS)/$(PATH_BONUS)/sound_and_music_bonus.c \
				$(PATH_SRCS)/$(PATH_COMMON)/angles.c \
				$(PATH_SRCS)/$(PATH_COMMON)/checkers.c \
				$(PATH_SRCS)/$(PATH_COMMON)/common.c \
				$(PATH_SRCS)/$(PATH_COMMON)/free_cub.c \
				$(PATH_SRCS)/$(PATH_COMMON)/math_utils.c \
				$(PATH_SRCS)/$(PATH_COMMON)/rgb.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/display.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/engine_loop.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/init_ray.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/raycasting_utils.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/raycasting.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/sprites_utils.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/sprites.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/handle_keys.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/quit_events.c \
				$(PATH_SRCS)/$(PATH_PARSER)/config_checker.c \
				$(PATH_SRCS)/$(PATH_PARSER)/init_cub.c \
				$(PATH_SRCS)/$(PATH_PARSER)/map_checker.c \
				$(PATH_SRCS)/$(PATH_PARSER)/map_parser.c \
				$(PATH_SRCS)/$(PATH_PARSER)/map_validator.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parser_utils.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parser.c

OBJS		=	$(SRCS:.c=.o)

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror# -g3 -fsanitize=address
RM			=	rm -f
RMRF		=	rm -rf

# Get system name
UNAME		:=	$(shell uname)


## Targets
# Check the system -- macOS or Linux -- for compilation

ifeq ($(UNAME), Darwin)
.c.o:
			$(MUTE) $(CC) $(CFLAGS) -Ofast -c $< -o $(<:.c=.o) -I incs -Ilibft/incs -Imlx
endif


ifeq ($(UNAME), Linux)
.c.o:
			$(MUTE) $(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I incs -Ilibft/incs -Imlx_linux
endif


ifeq ($(UNAME), Darwin)
$(NAME):	$(OBJS)
			@echo "\033[32;1mCOMPILING FOR macOS...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft...\033[0m"
			$(MUTE) $(MAKE) -C libft all
			@echo "\033[34;1m# 2/3 - Compiling mlx...\033[0m"
			$(MUTE) $(MAKE) -C mlx all
			$(MUTE) cp ./mlx/$(MLIBX) .
			@echo "\033[34;1m# 3/3 - Compiling project...\033[0m"
			$(MUTE) $(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx $(PATH_SRCS)/main.c $(SRCS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit $(INCS)
endif


ifeq ($(UNAME), Linux)
$(NAME):	$(OBJS)
			@echo "\033[32;1mCOMPILING FOR Linux...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft...\033[0m"
			$(MUTE) $(MAKE) -C libft all
			@echo "\033[34;1m# 2/3 - Compiling mlx...\033[0m"
			$(MUTE) $(MAKE) -C mlx_linux all
			@echo "\033[34;1m# 3/3 - Compiling project...\033[0m"
			$(MUTE) $(CC) $(CFLAGS) -I/usr/include -Imlx_linux $(PATH_SRCS)/main.c $(SRCS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


all:		$(NAME)


ifeq ($(UNAME), Darwin)
bonus:		$(OBJS)
			@echo "\033[32;1mCOMPILING BONUSES FOR macOS...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft...\033[0m"
			$(MUTE) $(MAKE) -C libft all
			@echo "\033[34;1m# 2/3 - Compiling mlx...\033[0m"
			$(MUTE) $(MAKE) -C mlx all
			$(MUTE) cp ./mlx/$(MLIBX) .
			@echo "\033[34;1m# 3/3 - Compiling project...\033[0m"
			$(MUTE) $(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx -DBONUS $(PATH_SRCS)/main.c $(SRCS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit $(INCS)
endif


ifeq ($(UNAME), Linux)
bonus:		$(OBJS)
			@echo "\033[32;1mCOMPILING BONUSES FOR Linux...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft...\033[0m"
			$(MUTE) $(MAKE) -C libft all
			@echo "\033[34;1m# 2/3 - Compiling mlx...\033[0m"
			$(MUTE) $(MAKE) -C mlx_linux all
			@echo "\033[34;1m# 3/3 - Compiling project...\033[0m"
			$(MUTE) $(CC) $(CFLAGS) -I/usr/include -Imlx_linux -DBONUS $(PATH_SRCS)/main.c $(SRCS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


ifeq ($(UNAME), Darwin)
clean:
			$(MUTE) $(MAKE) -C libft clean
			$(MUTE) $(MAKE) -C mlx clean
			$(MUTE) $(RM) $(OBJS)
endif


ifeq ($(UNAME), Linux)
clean:
			$(MUTE) $(MAKE) -C libft clean
			$(MUTE) $(MAKE) -C mlx_linux clean
			$(MUTE) $(RM) $(OBJS)
endif


fclean:		clean
			$(MUTE) $(MAKE) -C libft fclean
			$(MUTE) $(RM) $(MLIBX)
			$(MUTE) $(RM) $(BMP_FILE)
			$(MUTE) $(RM) $(NAME)


re:			fclean all


.PHONY:		$(NAME) all bonus clean fclean re
