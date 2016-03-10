/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:57:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/10 16:01:24 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;
	char c;

	char *l = setlocale(LC_ALL, "");
	if (l == NULL)
		printf("tamer\n");
	else
		printf("locale = %s\n", l);
/*	ret_ft = ft_printf("FT__{%10R}\n");
	ret = printf("NM__{%10R}\n");
	printf("ft_printf renvoie %d caracteres et printf renvoie %d caracteres\n", ret_ft, ret);*/
/*	ret_ft = ft_printf("{%-30S}", L"我是一只猫。");
	ft_putchar('\n');
	ret = printf("{%-30S}", L"我是一只猫。");
	ft_putchar('\n');
	printf("ft_printf renvoie %d caracteres et printf renvoie %d caracteres\n", ret_ft, ret);*/
/*	ret_ft = ft_printf("@main_ftprintf: {%###-#0000 33...12..#0+0d}\n", 256);
	ret  = printf("@main_ftprintf: {%###-#0000 33...12..#0+0d}\n", 256);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
	ret_ft = ft_printf("@main_ftprintf: {%####0000 33..1d}\n", 256);
	ret = printf("@main_ftprintf: {%####0000 33..1d}\n", 256);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);
	ret_ft = ft_printf("{%5+d}\n", 42);
	ret = printf("{%5+d}\n", 42);
	printf("FT renvoi : %d, NM renvoi : %d\n", ret_ft, ret);*/
	return (0);
}
