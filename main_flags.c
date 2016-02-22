/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:26:09 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/22 16:25:39 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;

	/************* Tests flag # *************/

	ret_ft = ft_printf("%+03d\n", 12);
	ret = printf("%+03d\n", 12);
/*	ret_ft = ft_printf("%+03d\n", 0);
	ret = printf("%+03d\n", 0);
	ret_ft = ft_printf("% 03d\n", 0);
	ret = printf("% 03d\n", 0); */
	printf("\nPRINTF renvoie %d caracteres et FT_PRINTF renvoie %d caracteres\n", ret, ret_ft);
	return (0);
}
