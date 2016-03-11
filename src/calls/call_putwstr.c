/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:40:51 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/11 12:38:18 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			count_wchar(wchar_t *str)
{
	FT_INIT(int, count, 0);
	FT_INIT(char *, bin, 0);
	FT_INIT(int, i, 0);
	while (str[i])
	{
		bin = ft_itoa_base(str[i], 2);
		if (ft_strlen(bin) <= 11)
			count += 2;
		else if (ft_strlen(bin) > 11 && ft_strlen(bin) <= 16)
			count += 3;
		else
			count += 4;
		free(bin);
		i++;
	}
	return (count);
}

int			ftp_dotw(wchar_t *str, unsigned int len)
{
	int		i;
	int count;

	i = 0;
	count = count_wchar(str);
	while (str[i] && i < count && i < (int)len)
	{
		ft_putwchar(str[i], 0);
		i++;
	}
	return (i);
}

int			ftp_distribw(t_docker *data, wchar_t *str, int len, int who)
{
	FT_INIT(int, ref, len);
	FT_INIT(int, count, 0);
	count = count_wchar(str);
	if (who == -1)
	{
		len += count;
		ft_putwstr(str, 0);
		return (len = ft_add_spaces((data->width - count), len, ' '));
	}
	else if (who == 0)
		return (len += ftp_dotw(str, data->precision));
	else if (who == 1)
	{
		len += ftp_dotw(str, data->precision);
		return (len = ft_add_spaces((data->width - (len - ref)), len, ' '));
	}
	else if (who == 2)
	{
		if (data->dot == !data->precision)
			return (len = ft_add_spaces(data->width, len, '0'));
		if (((len = ft_add_spaces(data->width - count > data->precision
								  ? data->precision : count, len, ' ')) >= 0))
			return (len += ftp_dotw(str, data->precision));
	}
	else if (who == 3)
		len = ft_add_spaces((data->width - count), len, data->zero ? '0' : ' ');
	return (len += ft_putwstr(str, 0));
}

int			call_putwstr(const char *str, va_list args, t_docker *data)
{
	wchar_t	*argument;

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
