# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 20:27:25 by besellem          #+#    #+#              #
#    Updated: 2021/07/02 19:39:14 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Constants
NAME		=	so_long
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

SRCS		=	$(PATH_SRCS)/$(PATH_OTHERS)/utils.c \
				$(PATH_SRCS)/$(PATH_BONUS)/minimap_bonus.c \
				$(PATH_SRCS)/$(PATH_COMMON)/free_all.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/display.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/engine_loop.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/handle_keys.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/quit_events.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parse_map.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parser.c \
				$(PATH_SRCS)/main.c

OBJS		=	$(SRCS:.c=.o)

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address
RM			=	rm -f
RMRF		=	rm -rf

# Get system name
UNAME		:=	$(shell uname)


## Targets
# Check the system -- macOS or Linux -- for compilation

ifeq ($(UNAME), Darwin)
.c.o:
			@$(CC) $(CFLAGS) -Ofast -c $< -o $(<:.c=.o) -I incs -Ilibft/incs -Imlx
endif


ifeq ($(UNAME), Linux)
.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I incs -Ilibft/incs -Imlx_linux
endif


ifeq ($(UNAME), Darwin)
$(NAME):	$(OBJS)
			@echo "\033[32;1mCOMPILING FOR macOS ...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft ...\033[0m"
			@$(MAKE) -C libft all >/dev/null
			@echo "\033[34;1m# 2/3 - Compiling mlx ...\033[0m"
			@$(MAKE) -C mlx all >/dev/null 2>&1
			@cp ./mlx/$(MLIBX) .
			@echo "\033[34;1m# 3/3 - Compiling project ...\033[0m"
			@$(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit $(INCS)
endif


ifeq ($(UNAME), Linux)
$(NAME):	$(OBJS)
			@echo "\033[32;1mCOMPILING FOR Linux ...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft ...\033[0m"
			@$(MAKE) -C libft all >/dev/null
			@echo "\033[34;1m# 2/3 - Compiling mlx ...\033[0m"
			@$(MAKE) -C mlx_linux all >/dev/null 2>&1
			@echo "\033[34;1m# 3/3 - Compiling project ...\033[0m"
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux $(OBJS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


all:		$(NAME)


ifeq ($(UNAME), Darwin)
bonus:		$(OBJS)
			@echo "\033[32;1mCOMPILING BONUSES FOR macOS ...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft ...\033[0m"
			@$(MAKE) -C libft all >/dev/null
			@echo "\033[34;1m# 2/3 - Compiling mlx ...\033[0m"
			@$(MAKE) -C mlx all >/dev/null 2>&1
			@cp ./mlx/$(MLIBX) .
			@echo "\033[34;1m# 3/3 - Compiling project ...\033[0m"
			@$(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx -DBONUS $(SRCS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit $(INCS)
endif


ifeq ($(UNAME), Linux)
bonus:		$(OBJS)
			@echo "\033[32;1mCOMPILING BONUSES FOR Linux ...\033[0m\n"
			@echo "\033[34;1m# 1/3 - Compiling libft ...\033[0m"
			@$(MAKE) -C libft all >/dev/null
			@echo "\033[34;1m# 2/3 - Compiling mlx ...\033[0m"
			@$(MAKE) -C mlx_linux all >/dev/null 2>&1
			@echo "\033[34;1m# 3/3 - Compiling project ...\033[0m"
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -DBONUS $(SRCS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


ifeq ($(UNAME), Darwin)
clean:
			@$(MAKE) -C libft clean >/dev/null
			@$(MAKE) -C mlx clean >/dev/null
			@$(RM) $(OBJS)
endif


ifeq ($(UNAME), Linux)
clean:
			@$(MAKE) -C libft clean >/dev/null
			@$(MAKE) -C mlx_linux clean >/dev/null
			@$(RM) $(OBJS)
endif


fclean:		clean
			@$(MAKE) -C libft fclean >/dev/null
			@$(RM) $(MLIBX)
			@$(RM) $(BMP_FILE)
			@$(RM) $(NAME)


re:			fclean all


.PHONY:		all bonus clean fclean re
