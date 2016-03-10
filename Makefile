#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/03/10 11:52:29 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_printf

# TILDE = ./src/*.c~ ./src/calls/*.c~  includes/*.h~ includes/*.h.gch Makefile~ \
./libptf/*.h~ ./libptf/*.h.gch ./libptf/*.c~ a.out /libftprintf/*.h~ \
./libftprintf/*.h.gch main.c~ Makefile~

LFT = ./libft/

L = ./libftprintf/

S = ./src/

C = ./src/calls/

LIBSRC = $(L)ftp_putbase.c $(L)ftp_putbase_long.c \
	$(L)ftp_putchar.c $(L)ftp_putnbr.c $(L)ftp_putnbr_long.c \
	$(L)ftp_putstr.c $(L)ftp_strlen.c

SRC = $(S)ft_check_valid.c $(S)ft_convert_length.c $(S)ft_detection.c \
	$(S)ft_printf.c

CALLS = $(C)call_purcent.c $(C)call_putadress.c $(C)call_putbase.c \
		$(C)call_putbase_long.c $(C)call_putchar.c $(C)call_putnbr.c \
		$(C)call_putnbr_long.c $(C)call_putstr.c $(C)call_putwchar.c \
		$(C)call_putwstr.c $(C)ft_add_spaces.c

SRCBIN = *.o

LIBBNRY = $(LIBSRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@printf "\033[31mCompilation de la libftprintf.a\033[0m"
	@make -C $(LFT) re
	@printf "\033[32m   Library done !\n\033[0m"
	@printf "\033[31mCompilation\033[0m "
	@$(CC) -o $(NAME) -I./includes/ft_printf.h $(LIBSRC) $(SRC) \
	$(CALLS) main_flags.c -I./includes/libft.h -L./libft/ -lft
	@$(CC) -c -I./ $(LIBSRC) $(SRC) -I./includes/libft.h
	@mv $(SRCBIN) $(L)
	@ar rcs libftprintf.a $(LIBBNRY) $(L)$(SRCBIN) ./includes/ft_printf.h
	@echo "\033[32m[OK]\033[0m"

clean:
	@printf "\033[31mNettoyage des dossiers\033[0m "
#	@rm -rf $(TILDE)
	@rm -rf $(LIBBNRY)
	@rm -rf $(L)*.o
	@echo "\033[32m[OK]\033[0m"

fclean: clean
	@printf "\033[31mNettoyage de tous les dossiers\033[0m "
	@make -C $(LFT) fclean
	@rm -rf $(NAME) inutile
	@rm -rf libftprintf.a
	@echo "\033[32m[OK]\033[0m"

push:
	@git add .
	@git commit -m "Makefile pushed"
	@git push

inutile:
	@find . -name "*~" -delete
	@find . -name "*#" -delete
	@find . -name "*.h.gch" -delete

re: fclean all