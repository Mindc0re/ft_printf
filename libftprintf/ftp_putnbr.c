/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:43:08 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/09 10:18:33 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putnbr(int32_t n, uint32_t space, uint32_t more)
{
	int sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strlen("-2147483648"));
	else
	{
		if (space == 1 && n >= 0)
			sign += ftp_putchar(' ');
		if (n < 0)
		{
			ftp_putchar('-');
			sign += 1;
			n = -n;
		}
		else if (n >= 0 && more == 1)
			sign += ftp_putchar('+');
		if (n >= 10)
			ftp_putnbr((n / 10), 0, 0);
		ftp_putchar((n % 10) + '0');
	}
	return (ft_strlen(ft_itoa(n)) + sign);
}
