/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:15:49 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/04 10:18:06 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char			*ft_detect_flags(char **str, t_docker *data)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
		|| **str == ' ' || **str == '.')
	{
		if (**str == ' ' && *(*str - 1) == '%')
			data->space = 1;
		else if (**str == ' ' && *(*str - 1) != '%')
			ft_putstr("error");
		if (**str == '#')
			data->dieze = 1;
		else if (**str == '+')
			data->more = 1;
		else if (**str == '0')
			data->zero = 1;
		else if (**str == '.')
		{
			(*str)++;
			data->dot = 1;
		}
		else if (**str == '-')
		{
			data->zero = 0;
			data->less = 1;
			(*str)++;
			ft_detect_width(str, data, -1);
		}
		else
			ft_detect_width(str, data, 1);
		(*str)++;
		ft_detect_flags(str, data);
	}
	return (*str);
}

char			*ft_detect_width(char **str, t_docker *data, int who)
{
	int			result;

	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (**str >= '0' && **str <= '9')
			result = result * 10 + (**str - 48);
		(*str)++;
		data->i++;
	}
	if (who == -1)
		data->width  = result;
	else if (who == 1)
	{
		data->dot = 1;
		data->precision = result;
	}
	return (*str);
}

char			*ft_detect_length(char **str, t_docker *data)
{
	if (**str == 'h' && *(*str + 1) != 'h')
		data->length = h;
	else if (**str == 'h' && *(*str + 1) == 'h')
	{
		data->length = hh;
		(*str) += 2;
	}
	else if (**str == 'l' && *(*str + 1) != 'l')
		data->length = l;
	else if (**str == 'l' && *(*str + 1) == 'l')
	{
		data->length = ll;
		(*str) += 2;
	}
	else if (**str == 'j')
		data->length = j;
	else if (**str == 'z')
		data->length = z;
	return (*str);
}
