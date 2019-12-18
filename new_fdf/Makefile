# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazalee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 19:57:32 by sazalee           #+#    #+#              #
#    Updated: 2019/12/18 13:32:19 by tstripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

ATTACH = -lmlx -framework OpenGL -framework AppKit -L./libft -lft

SRC = srcs/*.c

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME):
	    make -C libft/
		    gcc $(FLAGS) -I libft/ -c $(SRC)
			    gcc $(FLAGS) -o $(NAME) $(SRC) $(ATTACH)

clean:
	    rm -f $(OBJ)
		    make -C libft/ clean

fclean: clean
	    rm -f $(NAME)
		    make -C libft/ fclean

re: fclean all
