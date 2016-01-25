/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:53:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/25 16:02:36 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ftp_putbase(uint32_t n, uint32_t base)
{
	int len;

	len = 0;
	if (base > 0 && base <= 10)
	{
		if (n >= base)
			len += ftp_putbase((n / base), base);
		ft_putchar((n % base) + '0');
		len++;
	}
	else if (base == 16)
	{
		if (n >= 16)
		{
			len += ftp_putbase((n / 16), base);
			n %= 16;
		}
		if ((n % 16) >= 10)
			ft_putchar((n % 10) + 'A');
		else
			ft_putchar((n % 16) + '0');
		len++;
	}
	return (len);
}
