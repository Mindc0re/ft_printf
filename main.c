/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:32:37 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/12 17:58:49 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int ret_ft = 0, ret = 0;
	ret_ft = ft_printf("FT__%ll#x", 9223372036854775807);
	ft_printf("\n");
	ret = printf("NM__%ll#x", 9223372036854775807);
	printf("\nft_printf retourne %d caracteres et printf retourne %d caracteres\n", ret_ft, ret);

	ret_ft = ft_printf("%zhd", 4294967296);
	ft_printf("\n");
	ret = printf("%zhd", 4294967296);
	printf("\nft_printf retourne %d caracteres et printf retourne %d caracteres\n", ret_ft, ret);

	ret_ft = ft_printf("%hhld", 128);
	ft_printf("\n");
	ret = printf("%hhld", 128);
	printf("\nft_printf retourne %d caracteres et printf retourne %d caracteres\n", ret_ft, ret);
	return (0);
}
