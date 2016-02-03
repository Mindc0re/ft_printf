/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:43:08 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/03 09:20:02 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putnbr(int32_t n)
{
	int sign;

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
			ftp_putnbr(n / 10);
		ftp_putchar((n % 10) + '0');
	}
	return (ft_strlen(ft_itoa(n)) + sign);
}
