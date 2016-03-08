/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:04:14 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/08 12:22:44 by sgaudin          ###   ########.fr       */
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
		data->i += 2;
	else if (data->length == l || data->length == h || data->length == j
			|| data->length == z)
		data->i++;
}

uintmax_t		unsigned_conversion(t_docker *data, va_list args)
{
	uintmax_t tmp;

	tmp = 0;
	if (data->length == hh)
	{
		tmp = va_arg(args, unsigned int);
		return ((unsigned char)tmp);
	}
	if (data->length == h)
	{
		tmp = va_arg(args, unsigned int);
		return ((unsigned short)tmp);
	}
	else if (data->length == l)
		return (va_arg(args, unsigned long));
	else if (data->length == ll)
		return (va_arg(args, unsigned long long));
	else if (data->length == j)
		return (va_arg(args, uintmax_t));
	else if (data->length == z)
		return (va_arg(args, size_t));
	else
		return (va_arg(args, unsigned int));
}

intmax_t		signed_conversion(t_docker *data, va_list args)
{
	intmax_t tmp;

	tmp = 0;
	if (data->length == hh)
	{
		tmp = va_arg(args, int);
		return ((signed char)tmp);
	}
	if (data->length == h)
	{
		tmp = va_arg(args, int);
		return ((short)tmp);
	}
	if (data->length == ll)
		return (va_arg(args, long long));
	if (data->length == l)
		return (va_arg(args, long));
	if (data->length == j)
		return (va_arg(args, intmax_t));
	if (data->length == z)
		return (va_arg(args, size_t));
	else
		return (va_arg(args, int));
}
