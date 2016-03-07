/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:26:09 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/07 08:13:06 by sgaudin          ###   ########.fr       */
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
/*	ret_ft += ft_printf("FT__%#4o\n", 2500);
	ret += printf("PR__%#4o\n", 2500);
	ret += printf("PR__%0+5d\n", 42);
	ret_ft += ft_printf("FT__%0+5d\n", 42);
	ret += printf("PR__%0+5d\n", -42);
	ret_ft += ft_printf("FT__%0+5d\n", -42);
	ret += printf("PR__%-5+d\n", 42);
	ret_ft += ft_printf("FT__%-5+d\n", 42);
	ret += printf("PR__%-0+5d\n", 42);
	ret_ft += ft_printf("FT__%-0+5d\n", 42);
*/

	ret_ft = ft_printf("{% +d}\n", 42);
	ret = printf("{% +d}\n", 42);
	printf("PRINTF renvoie %d caracteres et FT_PRINTF renvoie %d caracteres\n", ret, ret_ft);
	ret_ft = ft_printf("{% 03d}\n", 0);
	ret = printf("{% 03d}\n", 0);
	printf("PRINTF renvoie %d caracteres et FT_PRINTF renvoie %d caracteres\n", ret, ret_ft);
	ret_ft = ft_printf("{%0-3d}\n", 0);
	ret = printf("{%0-3d}\n", 0);
	printf("PRINTF renvoie %d caracteres et FT_PRINTF renvoie %d caracteres\n", ret, ret_ft);
	return (0);
}
