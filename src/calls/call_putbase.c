/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:58:24 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 13:28:49 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putbase(char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 'u')
		return (ftp_putbase(va_arg(args, uint32_t), 10, 0, data->dieze));
	else if (str[data->i] == 'o')
	{
		return (ftp_putbase(va_arg(args, uint32_t), 8, 0, data->dieze));
	}
	else if (str[data->i] == 'x')
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'a', data->dieze));
	else if (str[data->i] == 'X')
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'A', data->dieze));
	else
		return (0);
}
