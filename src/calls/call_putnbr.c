/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:56:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/09 12:06:08 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putnbr(char *str, va_list args, t_docker *data)
{
	int		result;
	int		length;
	int		prec;

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
		while (length > 0)
		{
			ftp_putchar('0');
			length--;
		}
	}
	if (str[data->i] == 'd' || str[data->i] == 'i')
		return (ftp_putnbr(result, data->space, data->more) + prec);
	else
		return (0);
}
