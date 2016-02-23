#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/23 15:26:52 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Ceci est un Makefile TEMPORAIRE

NAME = ft_printf

TILDE = ./src/*.c~ ./src/calls/*.c~  includes/*.h~ includes/*.h.gch Makefile~ \
./libptf/*.h~ ./libptf/*.h.gch ./libptf/*.c~ a.out /libftprintf/*.h~ \
./libftprintf/*.h.gch main.c~ Makefile~

LIBFT = ./libft/

L = ./libftprintf/

LIBSRC = $(L)ftp_octal.c $(L)ftp_putbase.c $(L)ftp_putbase_long.c \
	$(L)ftp_putchar.c $(L)ftp_putnbr.c $(L)ftp_putnbr_long.c \
	$(L)ftp_putstr.c $(L)ftp_strlen.c

SRC = ./src/*.c ./src/calls/*.c

SRCBIN = *.o
LIBBNRY = $(LIBSRC:.c=.o)
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@printf "\033[31mCompilation de la libftprintf.a\033[0m"
	@make -C $(LIBFT) re
	@printf "\033[32m   Library done !\n\033[0m"
	@printf "\033[31mCompilation\033[0m "
	@gcc -o $(NAME) -I./includes/ft_printf.h $(LIBSRC) $(SRC) \
	main2.c -I./includes/libft.h -L./libft/ -lft
	@gcc -c -I./ $(LIBSRC) $(SRC) -I./includes/libft.h
	@mv $(SRCBIN) $(L)
	@ar rcs libftprintf.a $(LIBBNRY) $(L)$(SRCBIN) ./includes/ft_printf.h
	@echo "\033[32m[OK]\033[0m"

clean:
	@printf "\033[31mNettoyage des dossiers\033[0m "
	@make -C $(LIBFT) fclean
	@rm -rf $(TILDE)
	@echo "\033[32m[OK]\033[0m"

fclean: clean
	@printf "\033[31mNettoyage de tous les dossiers\033[0m "
	@rm -rf $(NAME) inutile
	@rm -rf $(LIBBNRY)
	@rm -rf libftprintf.a
	@rm -rf $(L)*.o
	@echo "\033[32m[OK]\033[0m"

push:
	@printf "Entrez votre commit \t"
	@git add .
	@read variable ; git commit -m $variable
	@git push

inutile:
	@find . -name "*~" -delete
	@find . -name "*#" -delete
	@find . -name "*.h.gch" -delete

re: fclean all