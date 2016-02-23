/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:56:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/23 14:58:38 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int		longueur_nb(int64_t nb, t_docker *data)
{
	FT_INIT(int, i, 1);
	i = nb >= 0 ? i : i + 1;
	nb = ft_abs(nb);
	while (nb > 9 && nb != -2147483648)
	{
		nb = nb / 10;
		i++;
	}
//	i = data->more == 1 ? i + 1 : i;
//	i = data->space == 1 ? i + 1 : i;
	if (nb == -2147483648)
		i = 11;
	return (i);
}

int		call_putnbr_part2(t_docker *data, int length, int prec, int result)
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
		ftp_putnbr(result, data);
		data->len = ft_add_spaces(length, data->len, ' ');
		return (0);
	}
	if (data->less == 0 && data->dot == 0 && data->width == 0)
		data->len += longueur_nb(result, data);
	return (1);
}

int		call_putnbr(const char *str, va_list args, t_docker *data)
{
	FT_INIT(int, length, 0);
	FT_INIT(int, result, va_arg(args, uint32_t));
	FT_INIT(int, prec, 0);
	FT_INIT(int, len_nb, longueur_nb(result, data) + data->more + data->space);
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
	if (call_putnbr_part2(data, length, prec, result) == 0)
		return (0);
	ftp_putnbr(result, data);
	return (0);
}
