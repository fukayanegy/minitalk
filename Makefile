SERVER_NAME	= server.exe
CLIENT_NAME	= client.exe
SERVER_SRC	= src/server.c
CLIENT_SRC	= src/client.c
LIBFT_SRCS	= libft/*.c
PRINTF_SRCS	= ft_printf/*.c
OBJS		= $(SRCS: .c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME_FLAGS	= -o

all:server client

server:
	$(CC) $(CFLAGS) $(NAME_FLAGS) $(SERVER_NAME) $(SERVER_SRC) $(LIBFT_SRCS) $(PRINTF_SRCS)

client:
	$(CC) $(CFLAGS) $(NAME_FLAGS) $(CLIENT_NAME) $(CLIENT_SRC) $(LIBFT_SRCS) $(PRINTF_SRCS)

clear:
	rm $(SERVER_NAME) $(CLIENT_NAME)
