/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:26:09 by sgaudin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/07 17:33:56 by sgaudin          ###   ########.fr       */
=======
/*   Updated: 2016/03/08 08:53:01 by dvirgile         ###   ########.fr       */
>>>>>>> c5f86cd794e238d99752d2f2fd3862376a9ae9d7
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

	ret_ft = ft_printf("{%0+5d}\n", -42);
	ret = printf("{%0+5d}\n", -42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%+10.5d}\n", 4242);
	ret = printf("{%+10.5d}\n", 4242);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{% 10.5d}\n", 4242);
	ret = printf("{% 10.5d}\n", 4242);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%-+10.5d}\n", 4242);
	ret = printf("{%-+10.5d}\n", 4242);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);
<<<<<<< HEAD

	ret_ft = ft_printf("{%03.2d}\n", -1);
	ret = printf("{%03.2d}\n", -1);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

=======
*/
	ret_ft = ft_printf("{%5+d}\n", 42);
	ret = printf("{%5+d}\n", 42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%5+d}\n", -42);
	ret = printf("{%5+d}\n", -42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%0+5d}\n", -42);
	ret = printf("{%0+5d}\n", -42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%-5+d}\n", 42);
	ret = printf("{%-5+d}\n", 42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%-0+5d}\n", 42);
	ret = printf("{%-0+5d}\n", 42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%0 d}\n", 42);
	ret = printf("{%0 d}\n", 42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

	ret_ft = ft_printf("{%0+5d}\n", 42);
	ret = printf("{%0+5d}\n", 42);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);

//	ret_ft = ft_printf("{%03.2d}\n", -1);
//	ret = printf("{%03.2d}\n", -1);
//	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);
/*
>>>>>>> c5f86cd794e238d99752d2f2fd3862376a9ae9d7
	ret_ft = ft_printf("@moulitest: {%5.d}, {%5.0d}\n", 0, 0);
	ret = printf("@moulitest: {%5.d}, {%5.0d}\n", 0, 0);
	printf("PRINTF renvoie {%d} caracteres et FT_PRINTF renvoie {%d} caracteres\n", ret, ret_ft);
	return (0);
}
