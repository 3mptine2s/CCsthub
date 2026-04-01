# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthubthi <sthubthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/01 12:31:34 by sthubthi          #+#    #+#              #
#    Updated: 2026/04/01 12:31:35 by sthubthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC	  		= cc
CFLAGS  	= -Wall -Wextra -Werror

SRC	 		= $(wildcard ./*.c)
OBJ	 		= $(SRC:.c=.o)

PRNTF		= ./ftprintf
PRNTFL		= $(PRNTF)/libftprintf.a
PRNTFI		= -I$(PRNTF)

MLX	 		= ./mlx_linux
MLXL		= $(MLX)/libmlx.a
MLXI		= -I$(MLX)
MLX_FLAGS 	= -L$(MLX) -lmlx -lXext -lX11 -lm


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