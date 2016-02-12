/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:06:28 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/12 12:24:03 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ftp_distrib_oct(t_docker *data, uint32_t nb, int len, int who)
{
	if (who == -1)
	{
		len += ftp_putbase(nb, 8, 0, data->dieze);
		return (len = ft_add_spaces((data->width - (int)ft_strlen(ft_itoa(nb))),
									len, ' '));
	}
//	else if (who == 0)
//		return (len += ftp_dot(nb, data->precision));
	return (len += ftp_putbase(nb, 8, 0, data->dieze));
}

int				ftp_octal(uint32_t nb, va_list args, t_docker *data)
{
	uint8_t		argument;

	argument = va_arg(args, uint32_t);
	if (data->width >= 1 && data->dot == 0 && data->less == 0) // avec un nombre
		data->len = ftp_distrib_oct(data, nb, data->len, 3);
	else if (data->dot == 1 && data->less == 1) // avec un '-' et un '.'
		data->len = ftp_distrib_oct(data, nb, data->len, 1);
	else if (data->less == 1 && data->dot == 0) // avec un '-'
		data->len = ftp_distrib_oct(data, nb, data->len, -1);
	else if (data->width >= 1 && data->dot == 1 && data->less == 0) // un nombre et un '.'
		data->len = ftp_distrib_oct(data, nb, data->len, 2);
	else if (data->dot == 1 && data->less == 0 && data->width == 0) // avec un '.'
		data->len = ftp_distrib_oct(data, nb, data->len, 0);
	else
		data->len = ftp_distrib_oct(data, nb, data->len, 4); // juste ave un o
	return (0);
}
