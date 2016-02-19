/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 08:44:49 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/19 09:52:21 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ftp_putnbr_long(int64_t n, uint32_t space, uint32_t more, int precision)
{
	int		len;

	len = 0;
	if (precision >= 0)
	{
		if (space == 1 && n > 0)
			len += ftp_putchar(' ');
		if (n < 0)
			n = -n;
		else if (n >= 0 && more == 1)
			len += ftp_putchar('+');
		if (n >= 10)
			len += ftp_putnbr((n / 10), 0, 0, precision--);
		len += ftp_putchar((n % 10) + '0');
	}
	return (len);
}
