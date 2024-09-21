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
CFLAGS := -Wall -Werror -Wextra -g
FT_PRINTF_DIR := ft_printf
FT_PRINTF := ${FT_PRINTF_DIR}/libftprintf.a
LIBFT_DIR := libft
LIBFT := ${LIBFT_DIR}/libft.a
SRC_FILE_NAMES := main check_cmd check_fork create_pipe initialize_paths \
									num_arg open_file pipey check_outfile free_things
SRCS := ${addsuffix .c, $(SRC_FILE_NAMES)}
OBJS := ${SRCS:.c=.o}

all: ${FT_PRINTF} ${LIBFT} $(NAME)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${FT_PRINTF} ${LIBFT} -o $@

clean:
	@make -C ${FT_PRINTF_DIR} clean
	@make -C ${LIBFT_DIR} clean
	rm -f ${OBJS}

${FT_PRINTF}:
	@make -C ${FT_PRINTF_DIR}

${LIBFT}:
	@make -C ${LIBFT_DIR}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

fclean: clean
	@make -C ${FT_PRINTF_DIR} fclean
	@make -C ${LIBFT_DIR} fclean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re