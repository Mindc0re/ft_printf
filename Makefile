#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/01/25 17:07:24 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Ceci est un Makefile TEMPORAIRE

NAME = ft_printf

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) ft_printf.c libftprintf/*.c libftprintf/*.h -L./ -lft

clean:
	rm -rf *.c~ *.h~

fclean: clean
	rm -rf $(NAME)

re: fclean all