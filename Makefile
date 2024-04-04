
NAME=bin
CC=cc
CFLAGS= -Wall -Wextra -Werror
CFILES= main.c \
get_next_line.c \
get_next_line_utils.c
OBJECTS=$(CFILES:.c=.o)

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
