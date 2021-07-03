# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 20:27:25 by besellem          #+#    #+#              #
#    Updated: 2021/07/04 01:07:08 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Constants
NAME		=	so_long

## Sources
INCS		=	-I incs -Llibft -lft -Ilibft/incs
MLIBX		=	libmlx.dylib

# Paths
PATH_SRCS	:=	./srcs

PATH_COMMON	:=	common
PATH_ENGINE	:=	engine
PATH_EVENTS	:=	events
PATH_PARSER	:=	parser

SRCS		=	$(PATH_SRCS)/$(PATH_COMMON)/free_all.c \
				$(PATH_SRCS)/$(PATH_COMMON)/utils.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/display.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/engine_loop.c \
				$(PATH_SRCS)/$(PATH_ENGINE)/map.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/handle_keys.c \
				$(PATH_SRCS)/$(PATH_EVENTS)/quit_events.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parse_map.c \
				$(PATH_SRCS)/$(PATH_PARSER)/parser.c \
				$(PATH_SRCS)/main.c

OBJS		=	$(SRCS:.c=.o)

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

# Colors
CLR_COLOR	:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

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
			@echo "COMPILING ON $(YELLOW)macOS $(CLR_COLOR)...\n"
			@echo "[1/3] - Compiling $(CYAN)libft $(CLR_COLOR)..."
			@$(MAKE) -C libft all >/dev/null
			@echo "[2/3] - Compiling $(CYAN)mlx $(CLR_COLOR)..."
			@$(MAKE) -C mlx all >/dev/null 2>&1
			@cp ./mlx/$(MLIBX) .
			@echo "[3/3] - Compiling $(RED)project $(CLR_COLOR)..."
			@$(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit $(INCS)
endif


ifeq ($(UNAME), Linux)
$(NAME):	$(OBJS)
			@echo "COMPILING ON $(YELLOW)Linux $(CLR_COLOR)...\n"
			@echo "[1/3] - Compiling $(CYAN)libft $(CLR_COLOR)..."
			@$(MAKE) -C libft all >/dev/null
			@echo "[2/3] - Compiling $(CYAN)mlx $(CLR_COLOR)..."
			@$(MAKE) -C mlx_linux all >/dev/null 2>&1
			@echo "[3/3] - Compiling $(RED)project $(CLR_COLOR)..."
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux $(OBJS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


all:		$(NAME)


ifeq ($(UNAME), Darwin)
bonus:		$(OBJS)
			@echo "COMPILING BONUSES ON $(YELLOW)macOS $(CLR_COLOR)...\n"
			@echo "[1/3] - Compiling $(CYAN)libft $(CLR_COLOR)..."
			@$(MAKE) -C libft all >/dev/null
			@echo "[2/3] - Compiling $(CYAN)mlx $(CLR_COLOR)..."
			@$(MAKE) -C mlx all >/dev/null 2>&1
			@cp ./mlx/$(MLIBX) .
			@echo "[3/3] - Compiling $(RED)project $(CLR_COLOR)..."
			@$(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx -DBONUS $(SRCS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit $(INCS)
endif


ifeq ($(UNAME), Linux)
bonus:		$(OBJS)
			@echo "COMPILING BONUSES ON $(YELLOW)Linux $(CLR_COLOR)...\n"
			@echo "[1/3] - Compiling $(CYAN)libft $(CLR_COLOR)..."
			@$(MAKE) -C libft all >/dev/null
			@echo "[2/3] - Compiling $(CYAN)mlx $(CLR_COLOR)..."
			@$(MAKE) -C mlx_linux all >/dev/null 2>&1
			@echo "[3/3] - Compiling $(RED)project $(CLR_COLOR)..."
			@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -DBONUS $(SRCS) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(INCS) -o $(NAME)
endif


clean:
			@echo "Cleaning $(CYAN)Libft$(CLR_COLOR) objects ..."
			@$(MAKE) -C libft clean >/dev/null
			@echo "Cleaning $(CYAN)mlx$(CLR_COLOR) objects ..."
			@$(MAKE) -C mlx_linux clean >/dev/null
			@$(RM) $(OBJS)


fclean:		clean
			@echo "Deleting $(CYAN)Libft$(CLR_COLOR) library ..."
			@$(MAKE) -C libft fclean >/dev/null
			@echo "Deleting $(CYAN)mlx$(CLR_COLOR) library ..."
			@$(RM) $(MLIBX)
			@echo "Deleting $(RED)$(NAME)$(CLR_COLOR) binary ..."
			@$(RM) $(NAME)


re:			fclean all


.PHONY:		all bonus clean fclean re
