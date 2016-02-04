/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:15:49 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/04 13:26:14 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char			*ft_detect_flags(char *str, t_docker *data)
{
	if (str[data->i] == '#' || str[data->i] == '0' || str[data->i] == '-' ||
		str[data->i] == '+'	|| str[data->i] == ' ' || str[data->i] == '.' ||
		(str[data->i] >= '0' && str[data->i] <= '9'))
	{
		if (str[data->i] == ' ' && str[data->i - 1] == '%')
			data->space = 1;
		else if (str[data->i] == ' ' && str[data->i - 1] != '%')
			ft_putstr("error");
		if (str[data->i] == '#')
			data->dieze = 1;
		else if (str[data->i] == '+')
			data->more = 1;
		else if (str[data->i] == '0')
			data->zero = 1;
		else if (str[data->i] == '.')
			data->dot = 1;
		else if (str[data->i] == '-')
		{
			data->zero = 0;
			data->less = 1;
			ft_putstr("\n\n\n");
			ft_detect_width(str, data, -1);
		}
		ft_detect_width(str, data, 1);
		data->i++;
		ft_detect_flags(str, data);
	}
	return (str);
}

char			*ft_detect_width(char *str, t_docker *data, int who)
{
	int			result;

	result = 0;
	while (str[data->i] >= '0' && str[data->i] <= '9')
	{
		if (str[data->i] >= '0' && str[data->i] <= '9')
			result = result * 10 + (str[data->i] - 48);
		data->i++;
	}
	if (who == -1)
		data->width  = result;
	else if (who == 1)
	{
		data->dot = 1;
		data->precision = result;
	}
	return (str);
}

char			*ft_detect_length(char *str, t_docker *data)
{
	if (str[data->i] == 'h' && str[data->i + 1] != 'h')
		data->length = h;
	else if (str[data->i] == 'h' && str[data->i + 1] == 'h')
	{
		data->length = hh;
		data->i += 2;
	}
	else if (str[data->i] == 'l' && str[data->i + 1] != 'l')
		data->length = l;
	else if (str[data->i] == 'l' && str[data->i + 1] == 'l')
	{
		data->length = ll;
		data->i += 2;
	}
	else if (str[data->i] == 'j')
		data->length = j;
	else if (str[data->i] == 'z')
		data->length = z;
	return (str);
}
