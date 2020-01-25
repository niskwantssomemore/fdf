# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazalee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 19:57:32 by sazalee           #+#    #+#              #
#    Updated: 2020/01/25 15:44:15 by sazalee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/check.c srcs/draw.c srcs/main.c srcs/mathdraw.c srcs/parse.c srcs/support.c srcs/interaction.c

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft
		gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a
		echo "Fdf done"

clean:
		make clean -C libft
		rm -f $(OBJ)

fclean: clean
		make fclean -C libft
		rm -f $(NAME)

re: fclean all
