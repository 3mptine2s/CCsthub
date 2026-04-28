NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC         = pushswap.c stack.c linkedList.c input_handler.c helper.c
OBJ         = $(SRC:.c=.o)

LIB         = ./libft
LIBL        = $(LIB)/libft.a
LIBI        = -I$(LIB)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBI) -c $< -o $@

$(LIBL):
	@make -C $(LIB)

$(NAME): $(OBJ) $(LIBL)
	$(CC) $(CFLAGS) $(OBJ) $(LIBL) -o $(NAME)

clean:
	rm -f $(OBJ)
	@make -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re