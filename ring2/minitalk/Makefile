
CC = gcc

CFLAGS = -I. -I./libft

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "Server compiled successfully!"

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "Client compiled successfully!"

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@make -C $(LIBFT_DIR) clean
	@echo "Object files removed."

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make -C $(LIBFT_DIR) fclean
	@echo "Executables removed."

re: fclean all

.PHONY: all clean fclean re