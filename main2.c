/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:31:07 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 16:19:16 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;

//	ret_ft += ft_printf("{%3c}\n", 0);
	//ret += printf("{%3c}\n", 0);

//	ret_ft += ft_printf("{%5p}\n", NULL);
//	ret += printf("{%5p}\n", NULL);
	ret_ft += ft_printf("%#o\n", 42);
	ret += printf("%#o\n", 42);
	printf("\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres", ret, ret_ft);
	return (0);
}
