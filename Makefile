NAME	= gcacb.a

FILES	= gc_funcs.c \
			gc_utils1.c \

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(FILES:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(FILES)
	ar -r -c $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re