/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:32:37 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/11 12:46:03 by sgaudin          ###   ########.fr       */
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
	char *test;

	test = setlocale(LC_ALL, "");
	if (!test)
		exit(EXIT_FAILURE);

	ret_ft = ft_printf("{%05p}", &test);
	printf("\n");
	ret = printf("{%05p}", &test);
	printf("\nft_printf renvoie %d caracteres et printf renvoie %d caracteres\n", ret_ft, ret);
	return (0);
}
