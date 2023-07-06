# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 19:00:14 by etakaham          #+#    #+#              #
#    Updated: 2023/07/06 19:08:10 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		= server.out
CLIENT_NAME		= client.out
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
SERVER_SRCS		= #
CLIENT_SRCS		= #
SERVER_OBJS		= $(SERVER_SRCS:.c = .o)
CLIENT_OBJS		= $(CLIENT_SRCS:.c = .o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(SERVER_NAME) $(CLIENT_NAME)

