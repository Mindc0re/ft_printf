/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:26:09 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/25 18:08:44 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;

	ft_putstr("\n\nTESTS A REGLER\n\n");
/*	ret_ft += ft_printf("%+03d\n", 0); // Probleme d'affichage
	ret += printf("%+03d\n", 0);
	ret_ft += ft_printf("% 03d\n", 0); // Probleme d'affichage
	ret += printf("% 03d\n", 0); */
	ret_ft = ft_printf("%ld\n", (long)INT_MAX + 1);
	ret = printf("%ld\n", (long)INT_MAX + 1);
//	ret_ft = ft_printf("FT__LONG MIN : %ld\n", LONG_MIN + 1);
//	ret = printf("NM__LONG MIN : %ld\n", LONG_MIN + 1);
	printf("\nPRINTF renvoie %d caracteres et FT_PRINTF renvoie %d caracteres\n\n", ret, ret_ft);
	return (0);
}










