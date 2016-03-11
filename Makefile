#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/03/11 19:08:09 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_printf

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


SRCBIN = ftp_putbase.o ftp_putbase_long.o ftp_putchar.o ftp_putnbr.o \
		ftp_putnbr_long.o ftp_putstr.o ftp_strlen.o call_purcent.o \
		call_putadress.o call_putbase.o call_putbase_long.o call_putchar.o \
		call_putnbr.o call_putnbr_long.o call_putstr.o call_putwchar.o \
		call_putwstr.o ft_add_spaces.o ft_check_valid.o ft_convert_length.o \
		ft_detection.o ft_printf.o

SRCBIN_L = $(L)ftp_putbase.o $(L)ftp_putbase_long.o $(L)ftp_putchar.o \
		$(L)ftp_putnbr.o $(L)ftp_putnbr_long.o $(L)ftp_putstr.o \
		$(L)ftp_strlen.o $(L)call_purcent.o $(L)call_putadress.o \
		$(L)call_putbase.o $(L)call_putbase_long.o $(L)call_putchar.o \
		$(L)call_putnbr.o $(L)call_putnbr_long.o $(L)call_putstr.o \
		$(L)call_putwchar.o $(L)call_putwstr.o $(L)ft_add_spaces.o \
		$(L)ft_check_valid.o $(L)ft_convert_length.o $(L)ft_detection.o \
		$(L)ft_printf.o

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@printf "\033[31mCompilation de la libftprintf.a\033[0m"
	@make -C $(LFT) re
	@printf "\033[32m   Library done !\n\033[0m"
	@printf "\033[31mCompilation\033[0m "
	@gcc -o $(NAME) -I./includes/ft_printf.h $(LIBSRC) $(SRC) \
	$(CALLS) main_flags.c -I./includes/libft.h -L./libft/ -lft
	@gcc -c -I./ $(LIBSRC) $(SRC) $(CALLS) -I./includes/libft.h
	@mv $(SRCBIN) $(L)
	@ar rcs libftprintf.a $(SRCBIN_L) ./includes/ft_printf.h
	@echo "\033[32m[OK]\033[0m"

clean:
	@printf "\033[31mNettoyage des dossiers\033[0m "
	@rm -rf $(SRCBIN_L)
	@echo "\033[32m[OK]\033[0m"

fclean: clean
	@printf "\033[31mNettoyage de tous les dossiers\033[0m "
	@make -C $(LFT) fclean
	@rm -rf $(NAME) inutile
#	@rm -rf inutile
	@rm -rf libftprintf.a
	@echo "\033[32m[OK]\033[0m"

push:
	@git add .
	@git commit -m "Makefile pushed"
	@git push

#inutile:
#	@find . -name "*~" -delete
#	@find . -name "*#" -delete
#	@find . -name "*.h.gch" -delete

re: fclean all