# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:25:53 by kdhrif            #+#    #+#              #
#    Updated: 2022/12/15 17:32:21 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = fdf
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS	:= $(shell find srcs/*.c -exec basename \ {} \;)
OBJS     = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS}}
CC       = gcc
CFLAGS   =
LIB      = mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a
HEADERS  = fdf.h

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "\033[33mcompiling ${NAME}..."
	@echo "SRCS = ${SRCS}"
	@echo "OBJS = ${OBJS}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o $@

${LIB} :
	@make -C mlx_linux

${NAME}: $(LIB) $(OBJS_DIR) $(OBJS) ${HEADERS}
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[32m$ ${NAME} compiled !"

clean:
	make -C mlx_linux clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re
