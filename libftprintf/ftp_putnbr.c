/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:43:08 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/19 12:16:06 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putnbr(int32_t nb, t_docker *data)
{
	int64_t		n;

	n = nb;
	if (data->precision >= 0)
	{
		if (data->space == 1 && n > 0)
		{
			data->len += ftp_putchar(' ');
			data->space = 0;
		}
		if (n < 0)
		{
			data->space = 0;
			n = -n;
		}
		else if (n >= 0 && data->more == 1)
		{
			data->len += ftp_putchar('+');
			data->more = 0;
		}
		if (n >= 10)
			ftp_putnbr((n / 10), data);
		ftp_putchar((n % 10) + '0');
	}
	return (0);
}
