/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:43:08 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/04 17:14:39 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ftp_putnbr(int64_t n, t_docker *data)
{

	if (data->precision >= 0)
	{
		if (data->space == 1 && data->more == 0 && n > 0)
		{
			data->len += ftp_putchar(' ');
			data->space = 0;
		}
		if (n >= 0 && data->more == 1)
		{
			data->len += ftp_putchar('+');
			data->more = 0;
			data->space = 0;
		}
		if (n < 0)
		{
			data->more = 0;
			data->space = 0;
			n = -n;
		}
		if (n >= 10)
			ftp_putnbr((n / 10), data);
		ftp_putchar((n % 10) + '0');
	}
	return (0);
}
