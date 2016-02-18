/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:49:27 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/18 14:38:00 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_printf.h"
#include <stdio.h>
#include <math.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;
	short test_short = 97;
	unsigned char test_uchar = ']';
	uint64_t test_ull = 256;
	uintmax_t test = 89;

	ret_ft += ft_printf("FT__ ---> Test adresse : %p\n\n\n", &test);
	ret += printf("____ ---> Test adresse : %p\n\n\n", &test);

	ret_ft += ft_printf("FT__ Flags avec long int ---> %hhU\n", test_uchar);
	ret += printf("____ Flags avec long int ---> %hhU\n", test_uchar);

	ret_ft += ft_printf("FT__ FLAG H ---> %-20hd\n", test_short);
	ret += printf("____ FLAG H ---> %-20hd\n", test_short);

	ret_ft += ft_printf("FT__ FLAG HH ---> %hhd\n", test_uchar);
	ret += printf("____ FLAG HH ---> %hhd\n", test_uchar);

	ret_ft += ft_printf("FT__ FLAG L ---> %ld\n", test);
	ret += printf("____ FLAG L ---> %ld\n", test);

	ret_ft += ft_printf("FT__ FLAG LL ---> %lld\n", test_ull);
	ret += printf("____ FLAG LL ---> %lld\n", test_ull);

	ret_ft += ft_printf("FT__ FLAG J ---> %jd\n", test);
	ret += printf("____ FLAG J ---> %jd\n", test);

	ret_ft += ft_printf("FT__ FLAG Z ---> %zd\n", test);
	ret += printf("____ FLAG Z ---> %zd\n", test);

//	ft_printf("%lc\n", L'é');
//	ret_ft += ft_printf("FT__ %-20.9x\n", -23456);
// ret += printf("PR__ %-20.9x\n", -23456);

//	ret_ft = ft_printf("FT__ %x %20x %2x %-20x %-2x %#x %#20x %#2x\n",255 , 255 , 255 , 255 , 255 , 255 , 255 , 255 );
//	ret = printf("PR__ %x %20x %2x %-20x %-2x %#x %#20x %#2x\n",255 , 255 , 255 , 255 , 255 , 255 , 255 , 255);
/*
	ret_ft += ft_printf("FT__%o %-20o %-3o %.o %.9o %.3o %20.10o %3.9o %3.3o\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret += printf("PR__%o %-20o %-3o %.o %.9o %.3o %20.10o %3.9o %3.3o\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret_ft += ft_printf("FT__%o%-20o%-3o%.o%.9o%.3o%20.10o%20.2o%3.9o%3.3o\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret += printf("PR__%o%-20o%-3o%.o%.9o%.3o%20.10o%20.2o%3.9o%3.3o\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret_ft = ft_printf("FT__ %o %20o %2o %-20o %-2o %#x %#20x %#2x\n",-255 , -255 , -255 , -255 , -255 , -255 , -255 , -255 );
	ret = printf("PR__ %o %20o %2o %-20o %-2o %#x %#20x %#2x\n",-255 , -255 , -255 , -255 , -255 , -255 , -255 , -255 );

	ret_ft += ft_printf("FT__%o %-20o %-3o %.o %.9o %.3o %20.10o %3.9o %3.3o\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("PR__%o %-20o %-3o %.o %.9o %.3o %20.10o %3.9o %3.3o\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret_ft += ft_printf("FT__%o%-20o%-3o%.o%.9o%.3o%20.10o%20.2o%3.9o%3.3o\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("PR__%o%-20o%-3o%.o%.9o%.3o%20.10o%20.2o%3.9o%3.3o\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret_ft += ft_printf("FT__%-o%-20o%-3o%-.o%-.9o%-.3o%-20.10o%-20.2o%-3.9o%-3.3o\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("PR__%-o%-20o%-3o%-.o%-.9o%-.3o%-20.10o%-20.2o%-3.9o%-3.3o\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);
*/
/*
	ret_ft += ft_printf("FT__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("% d\n", 10);
	ret_ft = ft_printf("FT__ %020x\n", -23456);
	ret = printf("PR__ %020x\n", -23456);

	ret_ft += ft_printf("FT__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("PR__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret_ft += ft_printf("FT__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret += printf("PR__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456, -23456);

	ret_ft += ft_printf("FT__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret += printf("PR__%d %-20d %-3d %.d %.9d %.3d %20.10d %20.2d %3.9d %3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret_ft += ft_printf("FT__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);

	ret += printf("PR__%-d %-20d %-3d %-.d %-.9d %-.3d %-20.10d %-20.2d %-3.9d %-3.3d\n", 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456, 23456);
*/

/*	ret_ft += ft_printf("FT_PRINTF %20s %-20s %s %3s %.s %.3s %20.3s %-20.3s\n", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon", "SimonSimon");
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
*/
	printf("Printf retourne %d caracteres, et ft_printf retourne %d caracteres\n", ret, ret_ft);
	//printf("\n   PRINTF : Test adresse de ret : %p", &ret);
	//ft_printf("\nFT_PRINTF : Test adresse de ret : %p\n", &ret);
	return (0);
}
