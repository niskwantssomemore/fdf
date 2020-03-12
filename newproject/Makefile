# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazalee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 19:57:32 by sazalee           #+#    #+#              #
#    Updated: 2020/03/12 16:13:07 by tstripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c read.c draw.c interaction.c

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
