# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:25:53 by kdhrif            #+#    #+#              #
#    Updated: 2022/11/30 17:25:51 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=fdf_init.c
OBJ=$(SRC:.c=.o)
CC=gcc

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make -C minilibx clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	rm -rf $(NAME)
