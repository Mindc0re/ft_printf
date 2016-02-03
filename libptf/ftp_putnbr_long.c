/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 08:44:49 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/03 09:20:23 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putnbr_long(long int n)
{
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strlen("-2147483648"));
	else
	{
		if (n < 0)
		{
			ftp_putchar('-');
			sign = 1;
			n = -n;
		}
		if (n >= 10)
			ftp_putnbr_long(n / 10);
		ftp_putchar((n % 10) + '0');
	}
	return (ft_strlen(ft_itoa(n)) + sign);
}
