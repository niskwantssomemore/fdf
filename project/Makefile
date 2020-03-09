# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazalee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 19:57:32 by sazalee           #+#    #+#              #
#    Updated: 2020/03/09 20:34:06 by sazalee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = check.c draw.c main.c mathdraw.c parse.c support.c interaction.c

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a

clean:
		@make clean -C libft
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all
