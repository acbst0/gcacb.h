NAME	= gcacb.a

FILES	= gc_funcs.c \
		gc_acb.c \

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(FILES:.c=.o)

$(NAME): $(OBJS)
	ar -r -c $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re