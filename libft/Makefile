# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 11:00:29 by lefendie          #+#    #+#              #
#    Updated: 2021/10/24 23:15:16 by lefendie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		:=	is_func/ft_isalnum.c is_func/ft_isalpha.c is_func/ft_isascii.c is_func/ft_isdbl.c is_func/ft_isdigit.c is_func/ft_isint.c is_func/ft_isprint.c\
					converter/ft_atoi.c converter/ft_atoi_dbl.c converter/ft_itoa.c\
					string/ft_skip.c string/ft_strchr.c string/ft_strcountc.c string/ft_striterc.c string/ft_strlcat.c string/ft_strlen.c string/ft_strncmp.c string/ft_strprfx.c string/ft_strset.c string/ft_strset.c string/ft_strsufx.c string/ft_substr.c string/ft_toupper.c string/ft_skip.c string/ft_strcontc.c string/ft_strdup.c string/ft_strjoin.c string/ft_strlcpy.c string/ft_strmapi.c string/ft_strnstr.c string/ft_strsrnd.c string/ft_strtrim.c string/ft_tolower.c\
					memory/ft_bzero.c memory/ft_calloc.c memory/ft_memccpy.c memory/ft_memchr.c memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c memory/ft_realloc.c\
					list/ft_lstadd_back.c list/ft_lstadd_front.c list/ft_lstclear.c list/ft_lstdelone.c list/ft_lstiter.c list/ft_lstlast.c list/ft_lstmap.c list/ft_lstnew.c list/ft_lstsize.c\
					print/ft_putchar_fd.c print/ft_putendl_fd.c print/ft_putnbr_fd.c print/ft_putstr_fd.c\
					other/ft_rand.c

OBJ	= ${SRC:.c=.o}

RM	= /bin/rm -rf

CC	= /usr/bin/clang

LIB = /usr/bin/ar -rcs

CFLAGS	= -Werror -Wextra -Wall -I .

%.o: %.c; ${CC} ${CFLAGS} -o $@ -c $<

${NAME}: ${OBJ}
	${LIB} ${NAME} ${OBJ}

all: ${NAME} 

clean:
	${RM} ${OBJ} ${OBJB}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: re clean fclean all so exec
