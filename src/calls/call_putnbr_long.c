/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:02:53 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/09 10:58:20 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			call_putnbr_long(char *str, va_list args, t_docker *data)
{
	int result;
	int length;

	if (str[data->i] == 'D')
	{
		result = va_arg(args, long int);
		if (data->dot == 1)
		{
			length = (int)ft_strlen(ft_itoa(data->precision));
			while (length >= 0)
			{
				ftp_putchar('0');
				length--;
			}
		}
		return(ftp_putnbr_long(result, data->space, data->more));
	}
	else
		return (0);
}
