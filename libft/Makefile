# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 17:47:06 by poliveir          #+#    #+#              #
#    Updated: 2021/03/02 14:36:37 by poliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#VARIABLES:

NAME		= libft.a

HFILE		= libft.h

SRCS		= ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c \
			ft_bzero.c ft_isdigit.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c \
			ft_calloc.c ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
			ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
			ft_isalpha.c ft_memccpy.c ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c

OBJS		= ${SRCS:.c=.o}

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS	= ${BONUS:.c=.o}

CC		= gcc

CFLAGS		= -c -Wall -Werror -Wextra -I.

AR		= ar

ARFLAGS		= -rcs

RM		= rm -rf

#RULES:

all: ${NAME}

$(NAME): ${OBJS}
	${AR} ${ARFLAGS} $@ $^

bonus: ${OBJS} ${BONUS_OBJS}
	${AR} ${ARFLAGS} ${NAME} $^

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
