/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 08:57:17 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 16:02:41 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putbase_long(long int n, long int base, int dieze)
{
	int len;

	len = 0;
	if (base > 0 && base <= 10)
	{
		if (base == 8 && n != 0 && dieze == 1)
			len += ftp_putchar('0');
		if (n >= base)
			len += ftp_putbase_long((n / base), base, 0);
		ft_putchar((n % base) + '0');
		len++;
	}
	return (len);
}
