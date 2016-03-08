/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 09:11:45 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/08 12:50:25 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;
/*	ret_ft += ft_printf("%+03d\n", 0); // Probleme d'affichage
	ret += printf("%+03d\n", 0);
	ret_ft += ft_printf("% 03d\n", 0); // Probleme d'affichage
	ret += printf("% 03d\n", 0); */
//	ret_ft += ft_printf("%4.15S\n", L"我是一只猫");
//	ret += printf("%4.15S\n", L"我是一只猫");
//	ret_ft += ft_printf("% \n");
//	ret += printf("% \n");

	ret_ft = ft_printf("FT__%d\n", INT_MIN - 1);
	ret = printf("NM__%d\n", INT_MIN - 1);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);


	return (0);
}
