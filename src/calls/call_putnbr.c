/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:56:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/09 10:51:49 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putnbr(char *str, va_list args, t_docker *data)
{
	int		result;
	int		length;

	if (str[data->i] == 'd' || str[data->i] == 'i')
	{
		result = va_arg(args, uint32_t);
		if (data->dot == 1 && data->precision != 0)
		{
			length = (int)ft_strlen(ft_itoa(data->precision));
			while (length >= 0)
			{
				ftp_putchar('0');
				length--;
			}
		}
		return (ftp_putnbr(result, data->space, data->more));
	}
	else
		return (0);
}








