/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:35:57 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/10 11:09:32 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;
/*	ret_ft = ft_printf("%");
	printf("|\n");
	ret = printf("%");
	printf("\nFT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
	ret_ft = ft_printf("FT__{% h}\n");
	ret = printf("NM__{% h}\n");
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);*/
/*	ret_ft += ft_printf("%+03d\n", 0); // Probleme d'affichage
	ret += printf("%+03d\n", 0);
	ret_ft += ft_printf("% 03d\n", 0); // Probleme d'affichage
	ret += printf("% 03d\n", 0); */
//	ret_ft += ft_printf("%4.15S\n", L"我是一只猫");
//	ret += printf("%4.15S\n", L"我是一只猫");
//	ret_ft += ft_printf("% \n");
//	ret += printf("% \n");
//	ft_printf("%hhld", "128");
//	printf("%hhld", "128");
//	ft_putstr("\n");
/*	ret_ft = ft_printf("FT__%%   %", "test");
	printf("\n");
	ret = printf("NM__%%   %", "test");
	printf("\nFT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);*/

	ret_ft = ft_printf("@main_ftprintf: {%###-#0000 33...12..#0+0d}\n", 256);
	ret  = printf("@main_ftprintf: {%###-#0000 33...12..#0+0d}\n", 256);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
	ret_ft = ft_printf("@main_ftprintf: {%####0000 33..1d}\n", 256);
	ret = printf("@main_ftprintf: {%####0000 33..1d}\n", 256);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
	ret_ft = ft_printf("{%5+d}\n", 42);
	ret = printf("{%5+d}\n", 42);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
/*	ret_ft = ft_printf("FT__{% Z}\n", 42);
	ret = printf("NM__{% Z}\n", 42);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);*/
	return (0);
}










