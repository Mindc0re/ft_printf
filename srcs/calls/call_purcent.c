/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_purcent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:14:18 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/14 11:14:18 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ftp_purcent(t_docker *data, int32_t str, int len, int who)
{
	int			ref;
	char		c;

	ref = len;
	c = data->zero ? '0' : ' ';
	if (who == -1)
	{
		len += ftp_putchar(str);
		return (len = ft_add_spaces((data->width - 1), len,
									data->zero == 1 ? '0' : ' '));
	}
	else if (who == 3)
	{
		if (data->dot == 1)
			c = '0';
		len = ft_add_spaces((data->width - 1), len, c);
	}
	return (len += str ? ftp_putchar(str) : 0);
}

int			call_purcent(const char *str, va_list args, t_docker *data)
{
	int32_t argument;

	argument = data->type;
	if (args)
		;
	if (data->width >= 1 && data->less == 0)
		data->len = ftp_purcent(data, argument, data->len, 3);
	else if (data->less == 1 && str)
		data->len = ftp_purcent(data, argument, data->len, -1);
	else
		data->len = ftp_purcent(data, argument, data->len, 4);
	return (0);
}
