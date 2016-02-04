#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/04 12:01:34 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Ceci est un Makefile TEMPORAIRE

NAME = ft_printf

TILDE = ./src/*.c~ ./src/calls/*.c~  includes/*.h~ includes/*.h.gch Makefile~ ./libptf/*.h~ ./libptf/*.h.gch ./libptf/*.c~ a.out

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) src/ft_printf.c main.c src/ft_detection.c src/calls/*.c libptf/*.c libptf/*.h includes/*.h -L./includes/ -lft

clean:
	rm -rf $(TILDE)

fclean: clean
	rm -rf $(NAME)

push:
	git commit -am "makefile pushed"
	git push

re: fclean all