#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/08 14:25:53 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Ceci est un Makefile TEMPORAIRE

NAME = ft_printf

TILDE = ./src/*.c~ ./src/calls/*.c~  includes/*.h~ includes/*.h.gch Makefile~ ./libptf/*.h~ ./libptf/*.h.gch ./libptf/*.c~ a.out

LIBFT = ./libft/

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C $(LIBFT) re
	$(CC) src/ft_printf.c main.c src/ft_detection.c src/calls/*.c libftprintf/*.c libftprintf/*.h includes/*.h -L./libft -lft

clean:
	rm -rf $(TILDE)

fclean: clean
	rm -rf $(NAME)

push:
	git commit -am "makefile pushed"
	git push

re: fclean all