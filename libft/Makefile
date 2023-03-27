CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=$(wildcard *.c)
NAME=libft.a
OBJS=$(SRCS:.c=.o)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
