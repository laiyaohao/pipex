# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 16:36:06 by ylai              #+#    #+#              #
#    Updated: 2024/09/02 19:06:21 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC_FILE_NAMES := main
SRC := $(addsuffix .c, $(SRC_FILE_NAMES))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c -o $(NAME)