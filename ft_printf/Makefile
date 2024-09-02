# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 14:02:37 by ylai              #+#    #+#              #
#    Updated: 2024/07/24 16:14:50 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC_DIR := ./src
# MAIN_DIR := ${SRC_DIR}/main/
# FLAG_DIR := ${SRC_DIR}/flags/
UTIL_DIR := ${SRC_DIR}/utils/

MAIN_FILES := ft_format ft_print_add ft_print_char ft_print_hex ft_print_int \
ft_print_str ft_print_uint ft_printf
UTIL_FILES := ft_abs ft_find_len ft_isnegative ft_itoa ft_itohex ft_ltoa \
ft_putchar ft_putstr ft_strlcpy ft_strlen ft_strdup
SRCS := $(addprefix $(UTIL_DIR), $(addsuffix .c, $(UTIL_FILES))) \
$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(MAIN_FILES)))
OBJS := ${SRCS:.c=.o}

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

${NAME}: ${OBJS}
	ar rcs $@ $^

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re