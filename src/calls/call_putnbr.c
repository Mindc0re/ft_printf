/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:56:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/12 12:35:38 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putnbr_bis(char *str, va_list args, t_docker *data)
{
	int		result;
	int		length;
	int		prec;

	prec = 0;
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
	int i;
//	int signe;

	i = 1;
//	signe = nb >= 0 ? 0 : ftp_putchar('-');
	i = nb >= 0 ? i : i + 1;//ftp_putchar('-');
	nb = ft_abs(nb);
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		call_putnbr(char *str, va_list args, t_docker *data)
{
	int		result;
	int		length;
	int		prec;
	int		len_nb;

	result = va_arg(args, uint32_t);
	prec = 0;
	length = 0;
	len_nb = longueur_nb(result);
//	ft_putstr("\n\nnb\n\n");
//	ft_putnbr(len_nb);
//	ft_putstr("\n\nnb\n\n");
	if (data->less == 0 && data->width > 0)
	{
		if (data->dot == 1)
			if ((data->precision - len_nb + (result >= 0 ? 0 : 1)) > 0)
				length -= data->precision - len_nb + (result >= 0 ? 0 : 1);
		length += data->width - len_nb;
		data->len += len_nb;
		data->len = ft_add_spaces(length, data->len, ' ');
	}
	if ((data->dot == 1 || data->less == 1) && result < 0)
		ftp_putchar('-');
	if (data->dot == 1 && str)
	{
		data->len += length != 0 || (length != 1 && result < 0) ? 0 : len_nb;
		length = data->precision - len_nb;
		length = result >= 0 ? length : length + 1;
		prec = data->len;
		data->len = ft_add_spaces(length, data->len, '0');
	}
	if (data->less == 1)
	{
		length = data->width - len_nb;
		length -= prec != 0 ? (data->len - prec) : 0;
		data->len += prec != 0 ? 0 : len_nb;
		ftp_putnbr(result, data->space, data->more, data->precision);
		data->len = ft_add_spaces(length, data->len, ' ');
		return (0);
		}
	if (data->less == 0 && data->dot == 0 && data->width == 0 && str)
		data->len += len_nb;
		if (data->less == 0 && data->dot == 0 && result < 0)
			ftp_putchar('-');
	ftp_putnbr(result, data->space, data->more, data->precision);
	return (0);
}
