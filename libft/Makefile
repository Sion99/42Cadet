CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=*.c
NAME=libft.a
OBJS=*.o

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re