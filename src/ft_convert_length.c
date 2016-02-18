/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:04:14 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 09:53:58 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			detect_conversion(const char *str, t_docker *data)
{
	data->length = (str[data->i] == 'h' && str[data->i + 1] == 'h') ? hh
					: 0;
	data->length = (str[data->i] == 'h' && data->length != hh) ? h
					: data->length;
	data->length = (str[data->i] == 'l' && str[data->i + 1] == 'l') ? ll
					: data->length;
	data->length = (str[data->i] == 'l' && data->length != ll) ? l
					: data->length;
	data->length = (str[data->i] == 'j') ? j : data->length;
	data->length = (str[data->i] == 'z') ? z : data->length;
	if (data->length == hh || data->length == ll)
	{
		ft_putnbr(data->length);
		data->i += 2;
	}
	else if (data->length == l || data->length == h || data->length == j
			|| data->length == z)
		data->i++;
}

uintmax_t		unsigned_conversion(uintmax_t val, t_docker *data)
{
	if (data->length == hh)
		return ((unsigned char)val);
	else if (data->length == h)
		return ((unsigned short)val);
	else if (data->length == ll)
		return ((unsigned long)val);
	else if (data->length == l)
		return ((unsigned long long)val);
	else if (data->length == j)
		return ((uintmax_t)val);
	else if (data->length == z)
		return ((size_t)val);
	else
		return (val);
}

intmax_t	signed_conversion(intmax_t val, t_docker *data)
{
	if (data->length == hh)
		return ((signed char)val);
	if (data->length == h)
		return ((short)val);
	if (data->length == ll)
		return ((long)val);
	if (data->length == l)
		return ((long long)val);
	if (data->length == j)
		return ((intmax_t)val);
	if (data->length == z)
		return ((size_t)val);
	else
		return (val);
}
