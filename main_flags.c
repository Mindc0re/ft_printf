/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 09:11:45 by sgaudin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/10 09:55:30 by sgaudin          ###   ########.fr       */
=======
/*   Updated: 2016/03/10 10:11:03 by dvirgile         ###   ########.fr       */
>>>>>>> b485c0c8822569802d15274b3dbc5010636fa546
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;
<<<<<<< HEAD
	ret_ft = ft_printf("%");
	ret = printf("%");
	printf("\nFT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
/*	ret_ft = ft_printf("%");
	printf("|\n");
	ret = printf("%");
	printf("\nFT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
	ret_ft = ft_printf("FT__{% h}\n");
	ret = printf("NM__{% h}\n");
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);*/
=======
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
	ret_ft = ft_printf("% ");
	ret = printf("% ");
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
>>>>>>> b485c0c8822569802d15274b3dbc5010636fa546
/*	ret_ft = ft_printf("FT__{% Z}\n", 42);
	ret = printf("NM__{% Z}\n", 42);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);*/
	return (0);
}
