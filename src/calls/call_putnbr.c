/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 09:10:59 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/08 10:10:19 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int		longueur_nb(int64_t nb, t_docker *data)
{
	FT_INIT(int, i, 1);
	i = nb >= 0 ? i : i + 1;
	nb = ft_abs(nb);
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		call_putnbr_part2(t_docker *data, int length, int prec, intmax_t res)
{
	if (data->less == 0 && data->width > 0)
		data->len += longueur_nb(res, data);
	if ((data->dot == 1 || data->less == 1) && res < 0 && data->zero == 0)
		ftp_putchar('-');
	data->more == 1 && res >= 0 && data->width != 0 && data->zero == 0
		? ftp_putchar('+') : 0;
	if (data->dot == 1)
	{
		data->len += (length == 0) ? longueur_nb(res, data) : 0;
		length = data->precision - longueur_nb(res, data);
		length = res >= 0 ? length : length + 1;
		prec = data->len;
		data->len = ft_add_spaces(length, data->len, '0');
	}
	if (data->less == 1)
	{
		length = data->width - longueur_nb(res, data) - (data->more && res >= 0 ? 1 : 0);
		length -= prec != 0 ? (data->len - prec) : 0;
		data->len += prec != 0 ? 0 : longueur_nb(res, data);
		ftp_putnbr(res, data);
		data->len = ft_add_spaces(length, data->len, data->zero == 1 ? '0' : ' ');
		return (0);
	}
	if (data->less == 0 && data->dot == 0 && data->width == 0)
		data->len += longueur_nb(res, data);
	return (1);
}

int		call_putnbr(const char *str, va_list args, t_docker *data)
{
	if (data->length == l || data->length == ll)
		return (call_putnbr_long(str, args, data));
	FT_INIT(int32_t, result, va_arg(args, int32_t));
	FT_INIT(int, len_nb, longueur_nb(result, data) +
	(data->more == 1 && result >= 0 ? 1 : 0) + data->space);
	FT_INIT(int, prec, (data->more == 1 && result >= 0
	&& (data->width == 0 || data->zero == 1)) ? ftp_putchar('+') : 0);
	result = signed_conversion(result, data);
	FT_INIT(int, length, 0);
	if (data->zero == 1 && result < 0 && str != NULL)
		ftp_putchar('-');
	if (data->less == 0 && data->width > 0)
	{
		if (data->dot == 1)
			if ((data->precision - len_nb + (result >= 0 ? 0 : 1)) > 0)
				length -= data->precision - len_nb + (result >= 0 ? 0 : 1);
		length += data->width - len_nb + (result == 0 && data->precision == 0 && data->dot == 1 ? 1 : 0)
			- (result >= 0 && data->more == 1 && data->zero == 0 ? 1 : 0);
		data->len = ft_add_spaces(length, data->len,
								  (data->zero == 1 && data->dot == 0 ? '0' : ' '));
		length = -1;
	}
	if (data->less == 0 && data->dot == 0 && result < 0 && data->zero == 0)
		ftp_putchar('-');
	if (result == 0 && data->precision == 0 && data->dot == 1 && data->less == 0)
		return (0);
	if (call_putnbr_part2(data, length, prec, result) == 0)
		return (0);
	return (ftp_putnbr(result, data));
}
