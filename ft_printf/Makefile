# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sishin <sishin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 13:02:34 by sishin            #+#    #+#              #
#    Updated: 2023/04/06 16:12:01 by sishin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_lib.c ft_lib2.c

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME 	=	libftprintf.a

all		:	${NAME}

%.o		:	%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
	ar -rc ${NAME} ${OBJS}

clean	:	
	rm -f ${OBJS}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
