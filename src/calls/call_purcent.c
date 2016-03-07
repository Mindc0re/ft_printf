/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:50:30 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/04 15:39:57 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int					ftp_dot_purcent(uint8_t *str, unsigned int len)
{
	int				i;

	i = 0;
	while (str[i] && i < ftp_strlen(str) && i < (int)len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int					ftp_distrib_purcent(t_docker *data, uint8_t *str, int len, int who)
{
	int				ref;

	ref = len;
	if (who == -1)
	{
		len += ftp_putstr(str);
		return (len = ft_add_spaces((data->width - ftp_strlen(str)), len, ' '));
	}
	else if (who == 0)
		return (len += ftp_dot_purcent(str, data->precision));
	else if (who == 1)
	{
		len += ftp_dot_purcent(str, data->precision);
		return (len = ft_add_spaces((data->width - (len - ref)), len, ' '));
	}
	else if (who == 2)
	{
		if ((len = ft_add_spaces(data->width - (ftp_strlen(str) >
		data->precision ? data->precision : ftp_strlen(str)), len, ' ')) >= 0)
			return (len += ftp_dot_purcent(str, data->precision));
	}
	else if (who == 3)
		len = ft_add_spaces((data->width - ftp_strlen(str)), len, ' ');
	return (len += ftp_putstr(str));
}

int					call_purcent(const char *str, va_list args, t_docker *data)
{
	uint8_t			*argument;

	if (data->length == l)
		return (ft_putwstr(va_arg(args, wchar_t *)));
	else
		argument = va_arg(args, uint8_t *);
	if (argument == NULL)
	{
		data->len += ftp_putstr((uint8_t *)"(null)");
		return (0);
	}/*
	if (data->width >= 1 && data->dot == 0 && data->less == 0)
		data->len = ftp_distrib(data, argument, data->len, 3);
	else if (data->dot == 1 && data->less == 1)
		data->len = ftp_distrib(data, argument, data->len, 1);
	else if (data->less == 1 && str && data->dot == 0)
		data->len = ftp_distrib(data, argument, data->len, -1);
	else if (data->width >= 1 && data->dot == 1 && data->less == 0)
		data->len = ftp_distrib(data, argument, data->len, 2);
	else if (data->dot == 1 && data->less == 0 && data->width == 0)
		data->len = ftp_distrib(data, argument, data->len, 0);
	else
	data->len = ftp_distrib(data, argument, data->len, 4);*/
		return (0);
}