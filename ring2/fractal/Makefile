NAME		= fractol
CC	  		= cc
CFLAGS  	= -Wall -Wextra -Werror

SRC	 		= test.c
OBJ	 		= $(SRC:.c=.o)

PRNTF   	= ./ftprintf
PRNTFL  	= $(PRNTF)/libftprintf.a
PRNTFI  	= -I$(PRNTF)

MLX	 		= ./mlx_linux
MLXL		= $(MLX)/libmlx.a
MLXI		= -I$(MLX)
MLX_FLAGS 	= -L$(MLX) -lmlx -lXext -lX11 -lm

# 'all' is at the top so it is the default rule
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(PRNTFI) $(MLXI) -c $< -o $@

$(MLXL):
	@make -C $(MLX)

$(PRNTFL):
	@make -C $(PRNTF)

$(NAME): $(OBJ) $(PRNTFL) $(MLXL)
	$(CC) $(CFLAGS) $(OBJ) $(PRNTFL) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	@make -C $(PRNTF) clean
	@make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(PRNTF) fclean

re: fclean all

.PHONY: all clean fclean re