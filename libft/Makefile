# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/13 02:01:30 by besellem          #+#    #+#              #
#    Updated: 2021/03/08 00:40:11 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MUTE		=	
NAME		=	libft.a

## Main srcs
SRCS_FOLDER	:=	srcs

# char
SRCS		+=	$(SRCS_FOLDER)/char/ft_isalnum.c \
				$(SRCS_FOLDER)/char/ft_isalpha.c \
				$(SRCS_FOLDER)/char/ft_isascii.c \
				$(SRCS_FOLDER)/char/ft_isdigit.c \
				$(SRCS_FOLDER)/char/ft_isprint.c \
				$(SRCS_FOLDER)/char/ft_tolower.c \
				$(SRCS_FOLDER)/char/ft_toupper.c

# conversion
SRCS		+=	$(SRCS_FOLDER)/conversion/ft_atod.c \
				$(SRCS_FOLDER)/conversion/ft_atoi_base.c \
				$(SRCS_FOLDER)/conversion/ft_atoi.c \
				$(SRCS_FOLDER)/conversion/ft_atol.c \
				$(SRCS_FOLDER)/conversion/ft_atold.c \
				$(SRCS_FOLDER)/conversion/ft_atoll.c \
				$(SRCS_FOLDER)/conversion/ft_itoa_base.c \
				$(SRCS_FOLDER)/conversion/ft_itoa.c \
				$(SRCS_FOLDER)/conversion/ft_nblen_base.c \
				$(SRCS_FOLDER)/conversion/ft_nblen.c \
				$(SRCS_FOLDER)/conversion/ft_strtol.c \
				$(SRCS_FOLDER)/conversion/ft_strtoll.c

# I/O
SRCS		+=	$(SRCS_FOLDER)/io/ft_putaddr_fd.c \
				$(SRCS_FOLDER)/io/ft_putaddr.c \
				$(SRCS_FOLDER)/io/ft_putc_fd.c \
				$(SRCS_FOLDER)/io/ft_putc.c \
				$(SRCS_FOLDER)/io/ft_putchar_fd.c \
				$(SRCS_FOLDER)/io/ft_putchar.c \
				$(SRCS_FOLDER)/io/ft_putendl_fd.c \
				$(SRCS_FOLDER)/io/ft_putendl.c \
				$(SRCS_FOLDER)/io/ft_putn_fd.c \
				$(SRCS_FOLDER)/io/ft_putn.c \
				$(SRCS_FOLDER)/io/ft_putnbr_fd.c \
				$(SRCS_FOLDER)/io/ft_putnbr.c \
				$(SRCS_FOLDER)/io/ft_putstr_fd.c \
				$(SRCS_FOLDER)/io/ft_putstr.c \
				$(SRCS_FOLDER)/io/get_next_line.c

# list
SRCS		+=	$(SRCS_FOLDER)/list/ft_lstadd_back.c \
				$(SRCS_FOLDER)/list/ft_lstadd_front.c \
				$(SRCS_FOLDER)/list/ft_lstclear.c \
				$(SRCS_FOLDER)/list/ft_lstdelone.c \
				$(SRCS_FOLDER)/list/ft_lstiter.c \
				$(SRCS_FOLDER)/list/ft_lstlast.c \
				$(SRCS_FOLDER)/list/ft_lstmap.c \
				$(SRCS_FOLDER)/list/ft_lstnew.c \
				$(SRCS_FOLDER)/list/ft_lstsize.c

# math
SRCS		+=	$(SRCS_FOLDER)/math/ft_factorial.c \
				$(SRCS_FOLDER)/math/ft_find_next_prime.c \
				$(SRCS_FOLDER)/math/ft_is_prime.c \
				$(SRCS_FOLDER)/math/ft_power.c

# memory
SRCS		+=	$(SRCS_FOLDER)/memory/ft_bzero.c \
				$(SRCS_FOLDER)/memory/ft_calloc.c \
				$(SRCS_FOLDER)/memory/ft_memccpy.c \
				$(SRCS_FOLDER)/memory/ft_memchr.c \
				$(SRCS_FOLDER)/memory/ft_memcmp.c \
				$(SRCS_FOLDER)/memory/ft_memcpy.c \
				$(SRCS_FOLDER)/memory/ft_memmove.c \
				$(SRCS_FOLDER)/memory/ft_memset.c

# str
SRCS		+=	$(SRCS_FOLDER)/str/ft_incharset.c \
				$(SRCS_FOLDER)/str/ft_strcapitalize.c \
				$(SRCS_FOLDER)/str/ft_strcasestr.c \
				$(SRCS_FOLDER)/str/ft_strcat.c \
				$(SRCS_FOLDER)/str/ft_strchr.c \
				$(SRCS_FOLDER)/str/ft_strcmp.c \
				$(SRCS_FOLDER)/str/ft_strcpy.c \
				$(SRCS_FOLDER)/str/ft_strdup.c \
				$(SRCS_FOLDER)/str/ft_stridx.c \
				$(SRCS_FOLDER)/str/ft_strisall.c \
				$(SRCS_FOLDER)/str/ft_strisalnum.c \
				$(SRCS_FOLDER)/str/ft_strisalpha.c \
				$(SRCS_FOLDER)/str/ft_strisascii.c \
				$(SRCS_FOLDER)/str/ft_strisdigit.c \
				$(SRCS_FOLDER)/str/ft_strisprint.c \
				$(SRCS_FOLDER)/str/ft_strjoin.c \
				$(SRCS_FOLDER)/str/ft_strlcat.c \
				$(SRCS_FOLDER)/str/ft_strlcpy.c \
				$(SRCS_FOLDER)/str/ft_strlen.c \
				$(SRCS_FOLDER)/str/ft_strlowcase.c \
				$(SRCS_FOLDER)/str/ft_strmapi.c \
				$(SRCS_FOLDER)/str/ft_strncat.c \
				$(SRCS_FOLDER)/str/ft_strncmp.c \
				$(SRCS_FOLDER)/str/ft_strncpy.c \
				$(SRCS_FOLDER)/str/ft_strndup.c \
				$(SRCS_FOLDER)/str/ft_strnlen.c \
				$(SRCS_FOLDER)/str/ft_strnstr.c \
				$(SRCS_FOLDER)/str/ft_stroc.c \
				$(SRCS_FOLDER)/str/ft_strpbrk.c \
				$(SRCS_FOLDER)/str/ft_strrchr.c \
				$(SRCS_FOLDER)/str/ft_strstr.c \
				$(SRCS_FOLDER)/str/ft_strtrim.c \
				$(SRCS_FOLDER)/str/ft_strupcase.c \
				$(SRCS_FOLDER)/str/ft_substr.c

# strs
SRCS		+=	$(SRCS_FOLDER)/strs/ft_split.c \
				$(SRCS_FOLDER)/strs/ft_strsjoin.c \
				$(SRCS_FOLDER)/strs/ft_strsplit.c


## Objects
OBJS		=	$(SRCS:.c=.o)

## Include
INCS			=	incs

## Commands
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
LIBC		=	ar rc
RM			=	rm -f

.c.o:
			$(MUTE) $(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			$(MUTE) $(MAKE) -C $(SRCS_FOLDER)/io/ft_printf
			$(MUTE) cp $(SRCS_FOLDER)/io/ft_printf/libftprintf.a ./$(NAME)
			$(MUTE) $(LIBC) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(MUTE) $(MAKE) -C $(SRCS_FOLDER)/io/ft_printf clean
			$(MUTE) $(RM) $(OBJS)

fclean:		clean
			$(MUTE) $(MAKE) -C $(SRCS_FOLDER)/io/ft_printf fclean
			$(MUTE) $(RM) $(NAME)

re:			fclean all

.PHONY:		$(NAME) all clean fclean re
