/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:20:55 by sgaudin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/02/15 10:33:10 by sgaudin          ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2016/02/15 10:38:40 by dvirgile         ###   ########.fr       */
=======
/*   Updated: 2016/02/15 09:54:23 by sgaudin          ###   ########.fr       */
>>>>>>> 1f70ea3cdfb19bf03f136d18d60a7dc9bd615985
>>>>>>> c97f78d004355c8bda88c9e8761ae90d0b6dcdd1
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
<<<<<<< HEAD
		data->zero = (str[data->i] == '0' && str[data->i - 1] == '%') ? 1 : data->zero;
=======
		data->zero = str[data->i] == '0' ? 1 : 0;
>>>>>>> 1f70ea3cdfb19bf03f136d18d60a7dc9bd615985
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
/*
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
*/
