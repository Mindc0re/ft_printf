/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:04:00 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/04 12:38:55 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <math.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;


	ret_ft = ft_printf("%s", "Coucou");
	ret = printf("%s", "Coucou");

//	ret_ft = ft_printf("FT_PRINTF : Simon = %s, c = %c\n", "Simon", 'c');
//	ret = printf("___PRINTF : Simon = %s, c = %c\n", "Simon", 'c');

//	ret_ft = ft_printf("FT_PRINTF : Coucou je suis %s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %#x et %X\n", "Simon", 17, 'Q', 500, 500);
//	ret = printf("   PRINTF : Coucou je suis %s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %#x et %X\n", "Simon", 17, 'Q', 500, 500);

//	ret_ft += ft_printf("FT_PRINTF : Ceci est un %De test : Vla un int en base 8 : %o, et un long int en base 8 : %O, et puis vla un long int en base 10 : %U\n", 2, 255, 255, 255);
//	ret += printf("   PRINTF : Ceci est un %De test : Vla un int en base 8 : %o, et un long int en base 8 : %O, et puis vla un long int en base 10 : %U\n", 2, 255, 255, 255);
	printf("Printf retourne %d caracteres, et ft_printf retourne %d caracteres\n", ret, ret_ft);
	//printf("\n   PRINTF : Test adresse de ret : %p", &ret);
	//ft_printf("\nFT_PRINTF : Test adresse de ret : %p\n", &ret);
	return (0);
}
