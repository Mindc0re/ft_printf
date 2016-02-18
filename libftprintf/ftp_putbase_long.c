/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 08:57:17 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 11:45:29 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putbase_long(long int n, uint32_t base, uint8_t flag, uint32_t dieze)
{
	int len;

	len = 0;
	if (base > 0 && base <= 10)
	{
		if (base == 8 && n != 0 && dieze == 1)
			len += ftp_putchar('0');
		if (n >= base)
			len += ftp_putbase((n / base), base, flag, 0);
		ft_putchar((n % base) + '0');
		len++;
	}
	else if (base == 16)
	{
		if (n != 0 && dieze == 1)
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
