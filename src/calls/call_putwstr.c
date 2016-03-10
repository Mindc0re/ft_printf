/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:40:51 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/10 09:50:39 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ftp_wstrlen(wchar_t *str)
{
	FT_INIT(int, len, 0);
	while (str[len] && str != NULL)
		len++;
	return (len);
}

int			ftp_dotw(wchar_t *str, unsigned int len)
{
	int		i;

	i = 0;
	while (str[i] && i < ftp_wstrlen(str) && i < (int)len)
	{
		ft_putwchar(str[i]);
		i++;
	}
	return (i);
}

int			ftp_distribw(t_docker *data, wchar_t *str, int len, int who)
{
	FT_INIT(int, ref, len);
	FT_INIT(int, width, data->width);
	if (who == -1)
	{
		len += ft_putwstr(str);
		return (len = ft_add_spaces((width -
		ftp_wstrlen(str)), len, ' '));
	}
	else if (who == 0)
		return (len += ftp_dotw(str, data->precision));
	else if (who == 1)
	{
		len += ftp_dotw(str, data->precision);
		return (len = ft_add_spaces((width - (len - ref)), len, ' '));
	}
	else if (who == 2)
	{
		if ((len = ft_add_spaces(width - (ftp_wstrlen(str) >
		data->precision ? data->precision : ftp_wstrlen(str)), len, ' ')) >= 0)
			return (len += ftp_dotw(str, data->precision));
	}
	else if (who == 3)
		len = ft_add_spaces((width - ftp_wstrlen(str)), len, ' ');
	return (len += ft_putwstr(str));
}

int			call_putwstr(const char *str, va_list args, t_docker *data)
{
	wchar_t	*argument;

	if (data->length == l)
		return (ft_putwstr(va_arg(args, wchar_t *)));
	else
		argument = va_arg(args, wchar_t *);
	if (argument == NULL)
	{
		data->len += ftp_putstr((uint8_t *)"(null)");
		return (0);
	}
	if (data->width >= 1 && data->dot == 0 && data->less == 0)
		data->len = ftp_distribw(data, argument, data->len, 3);
	else if (data->dot == 1 && data->less == 1)
		data->len = ftp_distribw(data, argument, data->len, 1);
	else if (data->less == 1 && str && data->dot == 0)
		data->len = ftp_distribw(data, argument, data->len, -1);
	else if (data->width >= 1 && data->dot == 1 && data->less == 0)
		data->len = ftp_distribw(data, argument, data->len, 2);
	else if (data->dot == 1 && data->less == 0 && data->width == 0)
		data->len = ftp_distribw(data, argument, data->len, 0);
	else
		data->len = ftp_distribw(data, argument, data->len, 4);
	return (0);
}
