/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:02:53 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 11:22:18 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			call_putnbr_long(const char *str, va_list args, t_docker *data)
{
	int result;

	if (str[data->i] == 'D')
	{
		result = va_arg(args, long int);
		result = signed_conversion(result, data);
		return (ftp_putnbr_long(result, data->space, data->more));
	}
	else
		return (0);
}
