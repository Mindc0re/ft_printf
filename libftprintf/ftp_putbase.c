/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:53:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/07 12:07:38 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ftp_putbase(uint32_t n, uint32_t base, uint8_t flag, t_docker *data)
{
	if (base > 0 && base <= 10)
	{
		if (base == 8 && data->dieze == 1)
			if (n != 0 || (n == 0 && data->precision <= 0))
				data->len += ftp_putchar('0');
		data->dieze = 0;
		if (n >= base)
			ftp_putbase((n / base), base, flag, data);
		ft_putchar((n % base) + '0');
	}
	else if (base == 16)
	{
		if (n != 0 && data->dieze == 1 && data->zero == 0)
			data->len += (ftp_putchar('0') + ftp_putchar(flag + 23));
		data->dieze = 0;
		if (n >= 16)
		{
			ftp_putbase((n / 16), base, flag, data);
			n %= 16;
		}
		ft_putchar((n % 16) >= 10 ? (n % 10) + flag : (n % 16) + '0');
	}
	return (0);
}
