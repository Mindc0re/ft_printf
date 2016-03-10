/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:50:30 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/10 11:38:03 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ftp_purcent(t_docker *data, int32_t str, int len, int who)
{
	int			ref;

	ref = len;
	if (who == -1)
	{
		len += ftp_putchar(str);
		return (len = ft_add_spaces((data->width - 1), len,
									data->zero == 1 ? '0' : ' '));
	}
	else if (who == 3)
		len = ft_add_spaces((data->width - 1), len,
							data->zero == 1 ? '0' : ' ');
	return (len += str ? ftp_putchar(str) : 0);
}

int			call_purcent(const char *str, va_list args, t_docker *data)
{
	int32_t argument;

	argument = '%';
	if (args)
		;
	while (str[data->i + 1] == '%')
		data->i++;
	if (data->width >= 1 && data->less == 0)
		data->len = ftp_purcent(data, argument, data->len, 3);
	else if (data->less == 1 && str)
		data->len = ftp_purcent(data, argument, data->len, -1);
	else
		data->len = ftp_purcent(data, argument, data->len, 4);
	return (0);
}
