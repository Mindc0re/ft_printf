/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:40:51 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/11 17:12:34 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int			count_wstr(wchar_t *str, int n, t_docker *data)
{
	FT_INIT(int, count, 0);
	FT_INIT(char *, bin, 0);
	FT_INIT(int, i, 0);
	if (!n)
		while (str[n])
			n++;
	while (str[i] && i < n)
	{
		bin = ft_itoa_base(str[i], 2);
		if (ft_strlen(bin) <= 7)
			count += 1;
		else if (ft_strlen(bin) <= 11)
			count += 2;
		else if (ft_strlen(bin) > 11 && ft_strlen(bin) <= 16)
			count += 3;
		else
			count += 4;
		free(bin);
		data->wide_width = i == 0 ? i + 1 : i;
		i++;
	}
	return (count);
}

int			count_wchar(wchar_t c)
{
	FT_INIT(int, count, 0);
	FT_INIT(char *, bin, 0);
	bin = ft_itoa_base(c, 2);
	if (ft_strlen(bin) <= 7)
		count += 1;
	else if (ft_strlen(bin) <= 11)
		count += 2;
	else if (ft_strlen(bin) > 11 && ft_strlen(bin) <= 16)
		count += 3;
	else
		count += 4;
	free(bin);
	return (count);
}

int			ftp_dotw(wchar_t *str, unsigned int len)
{
	int		i;
	int		count;
	int		count_check;

	i = 0;
	count = 0;
	count_check = 0;
	while (str[i] && (count_check += count_wchar(str[i])) <= len)
	{
		ft_putwchar(str[i], 0);
		i++;
		count += count_wchar(str[i]);
	}
	return (count);
}

int			ftp_distribw(t_docker *data, wchar_t *str, int len, int who)
{
	FT_INIT(int, ref, len);
	FT_INIT(int, count, 0);
	count = count_wstr(str, data->precision, data);
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
		if (data->dot && !data->precision)
			return (len = ft_add_spaces(data->width, len, (data->zero ? '0' : ' ')));
		if (((len = ft_add_spaces(data->width - data->wide_width, len, ' ')) >= 0))
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
