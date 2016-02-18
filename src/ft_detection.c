/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:50:02 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/18 10:02:16 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void			ft_detect_flags(const char *str, t_docker *data)
{
	if (ft_strchr("#0123456789-+ .", str[data->i]))
	{
		data->dieze = (str[data->i] == '#' && str[data->i - 1] == '%') ? 1 : data->dieze;
		data->more = str[data->i] == '+' ? 1 : 0;
		data->zero = (str[data->i] == '0' && str[data->i - 1] == '%') ? 1 : data->zero;
		data->space = (str[data->i] == ' ' && str[data->i - 1] == '%') ? 1 : data->space;
		if (str[data->i] == ' ' && str[data->i - 1] == '%')
			data->space = 1;
		else if (str[data->i] == '.')
		{
			data->result = 0;
			data->choice = 1;
			data->dot = 1;
			data->zero = 0;
		}
		if (str[data->i] == '-')
		{
			data->result = 0;
			data->choice = -1;
			data->zero = 0;
			data->less = 1;
		}
		ft_detect_width(str, data, data->choice);
		data->i++;
		ft_detect_flags(str, data);
	}
}

void			ft_detect_width(const char *str, t_docker *data, int who)
{
	if (str[data->i] >= '0' && str[data->i] <= '9')
	{
		data->result = data->result * 10 + (str[data->i] - 48);
		if (who == -1 || who == 0)
			data->width = data->result;
		else if (who == 1)
		{
			data->dot = 1;
			data->precision = data->result;
		}
	}
}
