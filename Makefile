.PHONY: all fclean re clean
SERVER_NAME	= server
CLIENT_NAME	= client
SERVER_SRC	= src/server.c
CLIENT_SRC	= src/client.c
LIBFT_SRCS	= libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c
PRINTF_SRCS	= ft_printf/ft_printf.c ft_printf/print_c.c ft_printf/print_di.c ft_printf/print_p.c ft_printf/print_s.c ft_printf/print_u.c ft_printf/print_xX.c
SRCS		= $(LIBFT_SRCS) $(PRINTF_SRCS)
OBJS		= $(SRCS: .c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME_FLAG	= -o
LEAK_FLAG	= -fsanitize=address -g

all:server client

OBJS		= $(SRCS:.c=.o)

$(SERVER_NAME):$(OBJS) $(SERVER_SRC)
	$(CC) $(CFLAGS) $(NAME_FLAG) $(SERVER_NAME) $(SERVER_SRC) $(OBJS)

$(CLIENT_NAME):$(OBJS) $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(NAME_FLAG) $(CLIENT_NAME) $(CLIENT_SRC) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re:fclean all
