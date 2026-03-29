NAME = libftprintf.a

MAIN_PART = ft_fputaddr.c ft_fputchar.c ft_fputnbr_deci.c ft_fputstr.c ft_funisignednbr.c \
			ft_printf.c ft_toupper.c ft_fputnbr_hex.c ft_fprint_nbr.c

# Object file
OBJS = ${MAIN_PART:.c=.o}

# Compiler and flag
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
RM = rm -f

%.o:%.c
	${CC} ${FLAGS} ${INCLUDE} -c $< -o $@ 

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean rel