# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/12 18:24:53 by chutterm          #+#    #+#              #
#    Updated: 2026/03/19 16:01:10 by chutterm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
DOT		:=	.c
FT		:=	ft_
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra

SRC		:=	isalpha isdigit isalnum isascii isprint strlen memset bzero \
			memcpy memmove strlcpy strlcat toupper tolower strchr \
			strrchr strncmp memchr memcmp strnstr atoi calloc strdup \
			substr strjoin strtrim split itoa strmapi striteri \
			putchar_fd putstr_fd putendl_fd putnbr_fd printf printf_utils \
			lstnew_bonus lstadd_front_bonus lstsize_bonus lstlast_bonus \
			lstadd_back_bonus lstdelone_bonus lstclear_bonus lstiter_bonus \
			lstmap_bonus safealloc

FILE	:=	$(addprefix $(FT), $(addsuffix $(DOT), $(SRC)))

OBJ		:=	$(FILE:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo "Packing libft..."
	@ar rcs $@ $^

%.o: %.c libft.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "Compiling: $(notdir $<)\n"

clean:
	rm -rf $(OBJ)

fclean:		clean 
	rm -rf $(NAME)

re:			fclean all