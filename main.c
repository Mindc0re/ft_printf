/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:22:04 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/15 09:33:57 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <math.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;

	ret_ft = ft_printf("FT__ %.d\n", 123456789);
	ret = printf("PR__ %.d\n", 123456789);

	ret_ft += ft_printf("% d\n", 10);
	ret += printf("% d\n", 10);
	ret_ft += ft_printf("FT__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("PR__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret_ft += ft_printf("FT__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("PR__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret_ft += ft_printf("FT__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret += printf("PR__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret_ft += ft_printf("FT__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret += printf("PR__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);


	ret_ft += ft_printf("FT_PRINTF %20s %-20s %s %3s %.s %.3s %20.3s %-20.3s\n", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon");
	ret += printf("___PRINTF %20s %-20s %s %3s %.s %.3s %20.3s %-20.3s\n", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon");

	ret_ft += ft_printf("FT_PRINTF : Simon = %-20.2s %.s %s %20s %2s test\n","SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon");
	ret += printf("___PRINTF : Simon = %-20.2s %.s %s %20s %2s test\n", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon");

	ret_ft += ft_printf("FT_PRINTF : Coucou je suis %-20s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %x et %X\n", "Simon", 17, 'Q', 500, 500);
	ret += printf("   PRINTF : Coucou je suis %-20s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %x et %X\n", "Simon", 17, 'Q', 500, 500);
	ret_ft += ft_printf("%#o\n", 500);
	ret += printf("%#o\n", 500);

	ret_ft += ft_printf("Test espace : % d\n", 500);
	ret += printf("Test espace : % d\n", 500);

	ret_ft += ft_printf("FT_PRINTF : Coucou je suis %s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %#x et %X\n", "Simon", 17, 'Q', 500, 500);
	ret += printf("   PRINTF : Coucou je suis %s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %#x et %X\n", "Simon", 17, 'Q', 500, 500);

	ret_ft += ft_printf("FT_PRINTF : Ceci est un %De test : Vla un int en base 8 : %o, et un long int en base 8 : %O, et puis vla un long int en base 10 : %U\n", 2, 255, 255, 255);
	ret += printf("   PRINTF : Ceci est un %De test : Vla un int en base 8 : %o, et un long int en base 8 : %O, et puis vla un long int en base 10 : %U\n", 2, 255, 255, 255);
	printf("Printf retourne %d caracteres, et ft_printf retourne %d caracteres\n", ret, ret_ft);
	//printf("\n   PRINTF : Test adresse de ret : %p", &ret);
	//ft_printf("\nFT_PRINTF : Test adresse de ret : %p\n", &ret);
	return (0);
}
