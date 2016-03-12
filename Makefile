#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2016/03/12 15:25:43 by sgaudin           #+#    #+#              #
#    Updated: 2016/03/12 15:40:02 by sgaudin          ###   ########.fr        #
=======
#    Created: 2016/01/25 16:57:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/03/12 16:04:04 by dvirgile         ###   ########.fr        #
>>>>>>> b9099245420d89779f8566980b6a3f9ad2b5bdf8
#                                                                              #
#******************************************************************************#

NAME = ft_printf

# TILDE = ./src/*.c~ ./src/calls/*.c~  includes/*.h~ includes/*.h.gch Makefile~ \
./libptf/*.h~ ./libptf/*.h.gch ./libptf/*.c~ a.out /libftprintf/*.h~ \
./libftprintf/*.h.gch main.c~ Makefile~

LFT = ./libft/

L = ./libftprintf/

S = ./srcs/

C = ./srcs/calls/

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

LIBFTBIN = $(LFT)ft_atoi.o $(LFT)ft_bzero.o $(LFT)ft_isalnum.o $(LFT)ft_isalpha.o \
		$(LFT)ft_isascii.o $(LFT)ft_isdigit.o $(LFT)ft_isprint.o $(LFT)ft_itoa.o \
		$(LFT)ft_memalloc.o $(LFT)ft_memccpy.o $(LFT)ft_memchr.o $(LFT)ft_memcmp.o \
		$(LFT)ft_memcpy.o $(LFT)ft_memdel.o $(LFT)ft_memmove.o $(LFT)ft_memset.o \
		$(LFT)ft_putchar.o $(LFT)ft_putchar_fd.o $(LFT)ft_putendl.o $(LFT)ft_putendl_fd.o \
		$(LFT)ft_putnbr.o $(LFT)ft_putnbr_fd.o $(LFT)ft_putstr.o $(LFT)ft_putstr_fd.o \
		$(LFT)ft_strcat.o $(LFT)ft_strchr.o $(LFT)ft_strclr.o $(LFT)ft_strcmp.o \
		$(LFT)ft_strcpy.o $(LFT)ft_strdel.o $(LFT)ft_strdup.o $(LFT)ft_strequ.o \
		$(LFT)ft_striter.o $(LFT)ft_striteri.o $(LFT)ft_strjoin.o $(LFT)ft_strlcat.o \
		$(LFT)ft_strlen.o $(LFT)ft_strmap.o $(LFT)ft_strmapi.o $(LFT)ft_strncat.o $(LFT)ft_strncmp.o \
		$(LFT)ft_strncpy.o $(LFT)ft_strnequ.o $(LFT)ft_strnew.o $(LFT)ft_strnstr.o $(LFT)ft_strrchr.o \
		$(LFT)ft_strsplit.o $(LFT)ft_strstr.o $(LFT)ft_strsub.o $(LFT)ft_strtrim.o $(LFT)ft_tolower.o \
		$(LFT)ft_toupper.o $(LFT)ft_lstnew.o $(LFT)ft_lstdelone.o $(LFT)ft_lstdel.o $(LFT)ft_lstadd.o \
		$(LFT)ft_lstiter.o $(LFT)ft_lstmap.o $(LFT)ft_sqrt.o $(LFT)ft_capitalize.o $(LFT)ft_printbase.o \
		$(LFT)ft_printhex.o $(LFT)ft_strtolower.o $(LFT)ft_strtoupper.o $(LFT)ft_abs.o \
		$(LFT)ft_print_list.o $(LFT)ft_lstadd_bottom.o $(LFT)ft_itoabase.o $(LFT)ft_putwchar.o \
		$(LFT)ft_atoibase.o $(LFT)ft_recursive_pow.o $(LFT)ft_putwstr.o

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@printf "\033[31mCompilation de la libftprintf.a\033[0m"
	@make -C $(LFT) re
	@cp $(LFT)libft.a ./
	@printf "\033[32m   Library done !\n\033[0m"
	@printf "\033[31mCompilation\033[0m "
<<<<<<< HEAD
#	@gcc -o $(NAME) -I./includes/ft_printf.h $(LIBSRC) $(SRC) \
#	$(CALLS) main_flags.c -I./includes/libft.h -L./libft/ -lft
	@gcc -c -I./ $(LIBSRC) $(SRC) $(CALLS) main_flags.c -I./includes/libft.h
	@gcc -o $(NAME) $(SRCBIN) -lft -L./
	@mv $(SRCBIN) $(L)
	@cp $(LFT)*.o $(L)
	@ar rcs libftprintf.a $(LIBBNRY) $(L)$(SRCBIN) ./includes/ft_printf.h
=======
	@$(CC) -c $(LIBSRC) $(SRC) $(CALLS) -I./includes/libft.h
	@$(CC) -o $(NAME) -I./includes/ft_printf.h $(LIBSRC) $(SRC) \
	$(CALLS) main.c -I./includes/libft.h -L./libft/ -lft
	@mv $(SRCBIN) $(L)
	@ar rcs libftprintf.a $(SRCBIN_L) $(LIBFTBIN) ./includes/ft_printf.h
>>>>>>> b9099245420d89779f8566980b6a3f9ad2b5bdf8
	@echo "\033[32m[OK]\033[0m"

clean:
	@printf "\033[31mNettoyage des dossiers\033[0m "
<<<<<<< HEAD
#	@rm -rf $(TILDE)
	@rm -rf libft.a
	@rm -rf $(LIBBNRY)
	@rm -rf $(L)*.o
=======
	@make -C $(LFT) clean
	@rm -rf $(SRCBIN_L) main.o
>>>>>>> b9099245420d89779f8566980b6a3f9ad2b5bdf8
	@echo "\033[32m[OK]\033[0m"

fclean: clean
	@printf "\033[31mNettoyage de tous les dossiers\033[0m "
	@make -C $(LFT) fclean
<<<<<<< HEAD
	@rm -rf $(NAME) inutile
=======
	@rm -rf $(NAME)
>>>>>>> b9099245420d89779f8566980b6a3f9ad2b5bdf8
	@rm -rf libftprintf.a
	@echo "\033[32m[OK]\033[0m"

push:
	@git add .
	@git commit -m "Makefile pushed"
	@git push

<<<<<<< HEAD
inutile:
	@find . -name "*~" -delete
	@find . -name "*#" -delete
	@find . -name "*.h.gch" -delete

=======
>>>>>>> b9099245420d89779f8566980b6a3f9ad2b5bdf8
re: fclean all