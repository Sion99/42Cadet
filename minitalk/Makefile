# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sishin <sishin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 16:34:38 by sishin            #+#    #+#              #
#    Updated: 2023/10/06 16:40:03 by sishin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	server
NAME2				=	client
CFLAG				=	-Werror -Wall -Wextra

CC					=	CC
RM					=	rm -rf

SRCS				=	server.c
SRCS2				=	client.c

OBJS				=	$(SRCS:%.c=%.o)
OBJS2				=	$(SRCS2:%.c=%.o)

all:				$(NAME) $(NAME2)

$(NAME):			$(OBJS)
						$(CC) $(CFLAG) $(OBJS) -o $(NAME)

$(NAME2):			$(OBJS2)
						$(CC) $(CFLAG) $(OBJS2) -o $(NAME2)

clean:
						$(RM) $(OBJS)
						$(RM) $(OBJS2)

fclean:				clean
						$(RM) $(NAME)
						$(RM) $(NAME2)

re:					fclean all

.PHONY:				all clean fclean re
