/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:02:53 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/24 16:46:27 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			putnbr_long_part2(t_docker *data, int length, int prec, int result)
{
	if (data->less == 0 && data->width > 0)
		data->len += longueur_nb(result, data);
	if ((data->dot == 1 || data->less == 1) && result < 0 && data->zero == 0)
		ftp_putchar('-');
	if (data->dot == 1)
	{
		data->len += (length == 0 || (length == 1 && result < 0))
			? longueur_nb(result, data) : 0;
		length = data->precision - longueur_nb(result, data);
		length = result >= 0 ? length : length + 1;
		prec = data->len;
		data->len = ft_add_spaces(length, data->len, '0');
	}
	if (data->less == 1)
	{
		length = data->width - longueur_nb(result, data);
		length -= prec != 0 ? (data->len - prec) : 0;
		data->len += prec != 0 ? 0 : longueur_nb(result, data);
		ftp_putnbr_long(result, data);
		data->len = ft_add_spaces(length, data->len, ' ');
		return (0);
	}
	if (data->less == 0 && data->dot == 0 && data->width == 0)
		data->len += longueur_nb(result, data);
	return (1);
}

int			call_putnbr_long(const char *str, va_list args, t_docker *data)
{
	FT_INIT(int, length, 0);
	FT_INIT(intmax_t, result, va_arg(args, intmax_t));
	FT_INIT(int, prec, 0);
	FT_INIT(int, len_nb, longueur_nb(result, data));
	result = signed_conversion(result, data);
	if (result == 0 && data->precision == 0 && data->width == 0 &&
		data->dot == 1 && data->less == 0)
		return (0);
	if (data->zero == 1 && result < 0 && str != NULL)
		ftp_putchar('-');
	if (data->less == 0 && data->width > 0)
	{
		if (data->dot == 1)
			if ((data->precision - len_nb + (result >= 0 ? 0 : 1)) > 0)
				length -= data->precision - len_nb + (result >= 0 ? 0 : 1);
		length += data->width - len_nb;
		data->len = ft_add_spaces(length, data->len,
								  (data->zero == 1 && data->dot == 0 ? '0' : ' '));
	}
	if (data->less == 0 && data->dot == 0 && result < 0 && data->zero == 0)
		ftp_putchar('-');
	if (putnbr_long_part2(data, length, prec, result) == 0)
		return (0);
	ftp_putnbr_long(result, data);
	return (0);
}
