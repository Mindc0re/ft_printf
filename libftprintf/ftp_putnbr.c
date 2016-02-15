/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:43:08 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/15 11:01:45 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putnbr(int32_t n, uint32_t space, uint32_t more, int precision)
{
	int sign;

	sign = 0;
	if (n == -2147483648 && precision >= 0)
		return (ft_strlen("-2147483648"));
	else if (precision >= 0)
	{
		if (space == 1 && n > 0)
			sign += ftp_putchar(' ');
		if (n < 0)
			n = -n;
		else if (n >= 0 && more == 1)
			sign += ftp_putchar('+');
		if (n >= 10)
			ftp_putnbr((n / 10), 0, 0, precision--);
		ftp_putchar((n % 10) + '0');
	}
	return ((int)ft_strlen(ft_itoa(n)));
}
