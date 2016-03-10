/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:57:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/10 17:43:36 by sgaudin          ###   ########.fr       */
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

	ret_ft = ft_printf("{%05.S}", L"42 c est cool");
	ft_putchar('\n');
	ret = printf("{%05.S}", L"42 c est cool");
	printf("\nft_printf renvoie %d caracteres et printf renvoie %d caracteres\n", ret_ft, ret);

/*	ret_ft = ft_printf("FT__{%#.3o}", 1);
	ft_putchar('\n');
	ret = printf("NM__{%#.3o}", 1);
	printf("\nft_printf renvoie %d caracteres et printf renvoie %d caracteres\n", ret_ft, ret);*/
	return (0);
}
