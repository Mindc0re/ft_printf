/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 11:13:38 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/15 11:18:59 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void			ft_detect_flags(char *str, t_docker *data)
{
	if (ft_strchr("#0123456789-+ .", str[data->i]))
	{
		data->dieze = str[data->i] == '#' ? 1 : 0;
		data->more = str[data->i] == '+' ? 1 : 0;
		data->zero = (str[data->i] == '0' && str[data->i - 1] == '%') ? 1 : data->zero;
		data->space = (str[data->i] == ' ' && str[data->i - 1] == '%') ? 1 : 0;
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

char			*ft_detect_width(char *str, t_docker *data, int who)
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
	return (str);
}
