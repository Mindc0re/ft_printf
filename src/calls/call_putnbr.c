/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:56:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/10 13:45:57 by dvirgile         ###   ########.fr       */
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
		return (ftp_putnbr(result, data->space, data->more) + prec);
	else
		return (0);
}

int		call_putnbr(char *str, va_list args, t_docker *data)
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
	else if (data->dot == 0 && data->less == 0 && data->width > 0)
		data->len = ft_add_spaces((data->width - (int)ft_strlen(ft_itoa(result))), data->len, ' ');
	else if (data->dot == 0 && data->less == 1 && data->width > 0)
	{
		data->len = ftp_putnbr(result, data->space, data->more);
		return (data->len = ft_add_spaces((data->width - (int)ft_strlen(ft_itoa(result))), data->len, ' '));
	}
	if (str[data->i] == 'd' || str[data->i] == 'i')
		return (ftp_putnbr(result, data->space, data->more) + prec);
	else
		return (0);
}
