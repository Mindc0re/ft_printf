/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:53:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 12:33:36 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putbase(uint32_t n, uint32_t base, uint8_t flag, int dieze)
{
	int len;

	len = 0;
	if (base > 0 && base <= 10)
	{
		if (n >= base)
			len += ftp_putbase((n / base), base, flag, dieze);
		ft_putchar((n % base) + '0');
		len++;
	}
	else if (base == 16)
	{
		if (n == 0 && dieze == 1)
			return (ftp_putchar('0'));
		else if (dieze == 1)
			len += (ftp_putchar('0') + ftp_putchar(flag + 23));
		if (n >= 16)
		{
			len += ftp_putbase((n / 16), base, flag, 0);
			n %= 16;
		}
		ft_putchar((n % 16) >= 10 ? (n % 10) + flag : (n % 16) + '0');
		len++;
	}
	return (len);
}
