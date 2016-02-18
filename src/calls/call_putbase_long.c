/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:07:37 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 11:17:01 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			call_putbase_long(const char *str, va_list args, t_docker *data)
{
	int		result;

	result = va_arg(args, long int);
	result = unsigned_conversion(result, data);
	if (str[data->i] == 'O')
		return (ftp_putbase_long(result, 8, data->dieze));
	else if (str[data->i] == 'U')
		return (ftp_putbase_long(result, 10, data->zero));
	else
		return (0);
}
