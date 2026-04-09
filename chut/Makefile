CLIENT_NAME	= client
SERVER_NAME	= server
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SOURCE_PATH	= src/
INCLUDE_PATH = include/
BUILD_PATH	= build/
LIBFT_PATH	= lib/libft/
LIBFT		= $(LIBFT_PATH)/libft.a

CLIENT_SRC	= client.c
SERVER_SRC	= server.c

CLIENT_OBJS = $(addprefix $(BUILD_PATH), $(CLIENT_SRC:.c=.o))
SERVER_OBJS = $(addprefix $(BUILD_PATH), $(SERVER_SRC:.c=.o))

all: $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_PATH)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJS)
	@echo "Linking $(CLIENT_NAME)..."
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT_NAME)
	@echo "$(CLIENT_NAME) build successful."

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJS)
	@echo "Linking $(SERVER_NAME)..."
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER_NAME)
	@echo "$(SERVER_NAME) build successful."

$(BUILD_PATH)%.o: $(SOURCE_PATH)%.c $(INCLUDE_PATH)/minitalk.h Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $< -o $@
	@printf "Compiling: $(notdir $<)\n"

clean:
	@make -C $(LIBFT_PATH) clean -s
	@rm -rf $(BUILD_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean -s
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re