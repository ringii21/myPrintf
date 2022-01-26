# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:12:51 by abonard           #+#    #+#              #
#    Updated: 2022/01/26 14:42:25 by abonard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-*-Makefile-*-

SRCS =					ft_len.c\
					ft_len_hexa.c\
					ft_number.c\
					ft_strlen_custom.c\
					ft_strcpy.c\
					ft_string.c\
					ft_parsing.c\
					ft_printf.c\
					ft_putnbr_base.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_putnbr_fd.c\
					ft_initialise_tab.c

HEAD		=		libftprintf.h

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rc libftprintf.a ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all	clean	fclean re
