/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:43:08 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 15:27:27 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putnbr(int32_t nb, uint32_t space, uint32_t more, int precision)
{
	int64_t		n;
	int			len;

	n = nb;
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
