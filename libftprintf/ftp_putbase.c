/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:53:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/25 14:26:38 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ftp_putbase(uint8_t n, uint32_t base)
{
	int len;

	len = 0;
	if (base == 2 || base == 10)
	{
		if (n >= base)
			len += ftp_putbase((n / base), base);
		ft_putchar((n % base) + '0');
		len++;
	}
	else if (base == 16)
	{
		if (n >= 16)
			len += ftp_putbase(n / 16, base);
		if ((n % 16) > 10)
			ft_putchar((n % 16) + 'A');
		else
			ft_putchar((n % 16) + '0');
		len++;
	}
	return (len);
}

int		main(int ac, char **av)
{
	int len = 0;
	if (ac == 3)
	{
		len = ftp_putbase(ft_atoi(av[1]), ft_atoi(av[2]));
		ft_putchar('\n');
		printf("\nLongueur retournee : %d\n", len);
	}
	return (0);
}
