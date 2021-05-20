# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 13:20:38 by poliveir          #+#    #+#              #
#    Updated: 2021/05/20 17:47:50 by poliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#VARIABLES:

LIBFT_PATH	= ./libft

NAME		= libftprintf.a

SRCS_DIR	= ./sources

HDRS_DIR	= ./headers

SRCS		= sources/ft_printf.c sources/ft_check_flags.c sources/ft_conversions.c sources/ft_chr_conv.c \
		  sources/ft_str_conv.c sources/ft_ptr_conv.c sources/ft_int_conv.c sources/ft_uns_int_conv.c \
		  sources/ft_hex_conv.c sources/ft_pct_conv.c sources/ft_count_digits_hex.c \
		  sources/ft_count_digits_sig.c sources/ft_count_digits_uns.c \
		  sources/ft_put_uns_int_fd.c sources/ft_put_dec_to_hex.c sources/ft_pad.c

OBJS		= ${SRCS:.c=.o}

LIBFT_SRCS	= libft/ft_atoi.c libft/ft_isascii.c libft/ft_memchr.c libft/ft_putchar_fd.c libft/ft_strchr.c \
			  libft/ft_strlen.c libft/ft_strtrim.c libft/ft_bzero.c libft/ft_isdigit.c libft/ft_memcmp.c \
			  libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strmapi.c libft/ft_substr.c libft/ft_calloc.c \
			  libft/ft_isprint.c libft/ft_memcpy.c libft/ft_putnbr_fd.c libft/ft_strjoin.c libft/ft_strncmp.c \
			  libft/ft_tolower.c libft/ft_isalnum.c libft/ft_itoa.c libft/ft_memmove.c libft/ft_putstr_fd.c \
			  libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_toupper.c libft/ft_isalpha.c libft/ft_memccpy.c \
			  libft/ft_memset.c libft/ft_split.c libft/ft_strlcpy.c libft/ft_strrchr.c libft/ft_lstnew.c \
			  libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c \
			  libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c

LIBFT_OBJS	= ${LIBFT_SRCS:.c=.o}

CC		= gcc

CFLAGS		= -c -Wall -Werror -Wextra -I${HDRS_DIR}

AR		= ar

ARFLAGS		= -rcs

RM		= rm -rf

#RULES:

all: ${NAME}

$(NAME): ${OBJS}
	${MAKE} re bonus -C ${LIBFT_PATH}
	${CC} ${CFLAGS} ${SRCS}
	${AR} ${ARFLAGS} $@ $^ ${LIBFT_OBJS}

clean:
	${RM} *.o ${SRCS_DIR}/*.o
	${MAKE} clean -C ${LIBFT_PATH}

fclean: clean
	${RM} ${NAME}	
	${MAKE} fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re
