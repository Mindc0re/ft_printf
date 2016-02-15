/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:04:14 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/15 10:30:54 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			detect_conversion(char *str, t_docker *data)
{
	data->length = (str[data->i] == 'h' && str[data->i + 1] == 'h') ? hh : 0;
	data->length = (str[data->i] == 'h' && data->length != 1) ? h : 0;
	data->length = (str[data->i] == 'l' && str[data->i + 1] == 'l') ? ll : 0;
	data->length = (str[data->i] == 'l' && data->length != 3) ? l : 0;
	data->length = (str[data->i] == 'j') ? j : 0;
	data->length = (str[data->i] == 'z') ? z : 0;
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
