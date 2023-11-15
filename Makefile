# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:33:23 by lsaumon           #+#    #+#              #
#    Updated: 2023/11/14 07:05:04 by lsaumon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		ft_printf_utils.c \
		ft_printnbr.c \

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
NAME = libftprintf.a

all: 		${NAME}

${NAME}: 	${OBJS}
			${AR} ${NAME} ${OBJS}

clean: 
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean ${NAME}

.PHONY:		all clean fclean re