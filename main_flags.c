/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:26:09 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/04 17:16:27 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;
	wchar_t *test = NULL;
//	ft_putstr("\n\nTESTS A REGLER\n\n");
/*	ret_ft += ft_printf("%+03d\n", 0); // Probleme d'affichage
	ret += printf("%+03d\n", 0);
	ret_ft += ft_printf("% 03d\n", 0); // Probleme d'affichage
	ret += printf("% 03d\n", 0); */
//	ret_ft += ft_printf("%4.15S\n", L"我是一只猫");
//	ret += printf("%4.15S\n", L"我是一只猫");
//	ret_ft += ft_printf("% \n");
//	ret += printf("% \n");
	ret_ft += ft_printf("FT__%#4o\n", 2500);
	ret += printf("PR__%#4o\n", 2500);
	ret += printf("PR__%0+5d\n", 42);
	ret_ft += ft_printf("FT__%0+5d\n", 42);
	ret += printf("PR__%0+5d\n", -42);
	ret_ft += ft_printf("FT__%0+5d\n", -42);
	ret += printf("PR__%-5+d\n", 42);
	ret_ft += ft_printf("FT__%-5+d\n", 42);
	ret += printf("PR__%-0+5d\n", 42);
	ret_ft += ft_printf("FT__%-0+5d\n", 42);

	printf("PRINTF renvoie %d caracteres et FT_PRINTF renvoie %d caracteres\n", ret, ret_ft);
	return (0);
}
