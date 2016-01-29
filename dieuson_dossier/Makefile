#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 17:52:26 by sgaudin           #+#    #+#              #
#    Updated: 2016/01/28 15:23:14 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_printf

SRC = ft_printf.c ftp_hh_flags.c ./src/ftp_converters.c ./src/ft_detection.c ./src/ftp_int.c

TILDE = $(SRC:.c=.c~) Makefile~ ./includes/ft_printf.h.gch ./includes/ft_printf.h~ ./includes/ft_detection.h~

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I./includes -L./ -lft $(SRC) -o $(NAME)

clean:
	rm -rf $(TILDE)

fclean: clean
	rm -rf $(NAME)

re: fclean all
