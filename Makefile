#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/01 18:14:20 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Ceci est un Makefile TEMPORAIRE

NAME = ft_printf

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) src/ft_printf.c src/calls/*.c libptf/*.c libptf/*.h includes/*.h -L./includes/ -lft

clean:
	rm -rf *.c~ *.h~

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

push:
	git commit -am "makefile pushed"
	git push

re: fclean all