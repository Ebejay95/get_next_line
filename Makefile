NAME = bin
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = get_next_line.c \
		get_next_line_utils.c
CFILESB = get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJECTS = $(CFILES:.c=.o)
OBJECTSB = $(CFILESB:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(NAMEB): $(OBJECTSB)
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJECTSB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTSB)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEB)

re: fclean all
