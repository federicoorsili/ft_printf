# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: forsili <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 16:07:41 by forsili           #+#    #+#              #
#    Updated: 2021/01/13 16:07:43 by forsili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

AR = ar -rc

RAN = ranlib

SRCS =	\
ft_atoi.c\
ft_bzero.c\
ft_isdigit.c\
ft_itoa.c\
ft_putnbr_base.c\
ft_strdup.c\
ft_strlcpy.c\
ft_uns_itoa.c\
generale.c\
stampe.c	


OBJS = ${SRCS:.c=.o}


RM = rm -f

%.o: %.c
	${CC} ${CFLAGS} $<

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}
	${RAN} ${NAME}


all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
