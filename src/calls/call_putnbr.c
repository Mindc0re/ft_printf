/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:56:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 09:59:18 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putnbr_bis(const char *str, va_list args, t_docker *data)
{
	FT_INIT(int, result, va_arg(args, uint32_t));
	FT_INIT(int, prec, 0);
	FT_INIT(int, length, 0);
	result = va_arg(args, uint32_t);
	if (data->dot == 1 && data->precision != 0)
	{
		length = data->precision - (int)ft_strlen(ft_itoa(result));
		prec = result >= 0 ? length : length + 1;
		if (result < 0)
		{
			length += 1;
			prec += ftp_putchar('-');
		}
		result = ft_abs(result);
		while ((length--) > 0)
			ftp_putchar('0');
	}
	if (str[data->i] == 'd' || str[data->i] == 'i')
		return (ftp_putnbr(result, data->space, data->more,
				(int)ft_strlen(ft_itoa(result)) + prec));
	else
		return (0);
}

int		longueur_nb(int32_t nb)
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

int		call_putnbr_part2(t_docker *data, int length, int prec, int result)
{
	if ((data->dot == 1 || data->less == 1) && result < 0 && data->zero == 0)
		ftp_putchar('-');
	if (data->dot == 1)
	{
		data->len += (length == 0 || (length == 1 && result < 0))
		? longueur_nb(result) : 0;
		length = data->precision - longueur_nb(result);
		length = result >= 0 ? length : length + 1;
		prec = data->len;
		data->len = ft_add_spaces(length, data->len, '0');
	}
	if (data->less == 1)
	{
		length = data->width - longueur_nb(result);
		length -= prec != 0 ? (data->len - prec) : 0;
		data->len += prec != 0 ? 0 : longueur_nb(result);
		ftp_putnbr(result, data->space, data->more, data->precision);
		data->len = ft_add_spaces(length, data->len, ' ');
		return (0);
	}
	if (data->less == 0 && data->dot == 0 && data->width == 0)
		data->len += longueur_nb(result);
	return (1);
}

int		call_putnbr(const char *str, va_list args, t_docker *data)
{
	FT_INIT(int, length, 0);
	FT_INIT(int, result, va_arg(args, uint32_t));
	FT_INIT(int, prec, 0);
	FT_INIT(int, len_nb, longueur_nb(result));
	if (data->zero == 1 && result < 0 && str != NULL)
		ftp_putchar('-');
	if (data->less == 0 && data->width > 0)
	{
		if (data->dot == 1)
			if ((data->precision - len_nb + (result >= 0 ? 0 : 1)) > 0)
				length -= data->precision - len_nb + (result >= 0 ? 0 : 1);
		length += data->width - len_nb;
		data->len += len_nb;
		data->len = ft_add_spaces(length, data->len,
		(data->zero == 1 && data->dot == 0 ? '0' : ' '));
	}
	if (data->less == 0 && data->dot == 0 && result < 0 && data->zero == 0)
		ftp_putchar('-');
	if (call_putnbr_part2(data, length, prec, result) == 0)
		return (0);
	ftp_putnbr(result, data->space, data->more, data->precision);
	return (0);
}
