/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 08:44:49 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/02 15:21:46 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int			ftp_putnbr_long(int64_t n, t_docker *data)
{
	int					len;

	len = 0;
	if (data->precision >= 0)
	{
		if (data->space == 1 && n > 0)
			data->len += ftp_putchar(' ');
		if (n < 0)
			n = -n;
		else if (n >= 0 && data->more == 1)
			data->len += ftp_putchar('+');
		if (n >= 10)
			len += ftp_putnbr((n / 10), data);
		len += ftp_putchar((n % 10) + '0');
	}
	return (len);
}




