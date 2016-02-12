#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/12 09:47:21 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Ceci est un Makefile TEMPORAIRE

NAME = ft_printf

TILDE = ./src/*.c~ ./src/calls/*.c~  includes/*.h~ includes/*.h.gch Makefile~ ./libptf/*.h~ ./libptf/*.h.gch ./libptf/*.c~ a.out /libftprintf/*.h~ ./libftprintf/*.h.gch main.c~ Makefile~

LIBFT = ./libft/

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "\033[32mCompilation\033[0m"
	@make -C $(LIBFT) re
	@$(CC) src/ft_printf.c main.c src/ft_detection.c src/calls/*.c libftprintf/*.c libftprintf/*.h includes/*.h -L./libft -lft

clean:
	@echo "\033[35mNettoyage des dossiers\033[0m"
	@make -C $(LIBFT) fclean
	@rm -rf $(TILDE)

fclean: clean
	@echo "\033[31mNettoyage de tous les dossiers\033[0m"
	@rm -rf $(NAME)

push:
	@echo "Entrez votre commit"
	@git add .
	@read variable ; git commit -m $variable
	@git push

re: fclean all