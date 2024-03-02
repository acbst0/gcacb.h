NAME	= gcacb.a

FILES	= gc_utils1.c \
			gc_funcs.c \

OBJ		= $(FILES:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(FILES)
	ar -rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re