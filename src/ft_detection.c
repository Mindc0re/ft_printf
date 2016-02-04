/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:15:49 by dvirgile          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/02/04 15:49:56 by sgaudin          ###   ########.fr       */
=======
/*   Updated: 2016/02/04 17:56:45 by dvirgile         ###   ########.fr       */
>>>>>>> 259255a5d80444d1ad35414472aebcaee5ef0e75
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
		else if (str[data->i] == '#')
			data->dieze = 1;
		else if (str[data->i] == '+')
		{
			if (data->zero == 1)
				data->zero = 0;
			data->more = 1;
		}
		else if (str[data->i] == '0' && data->more == 0)
			data->zero = 1;
		else if (str[data->i] == '.')
		{
			data->choice = 1;
			data->dot = 1;
		}
		if (str[data->i] == '-')
		{
			data->choice = -1;
			data->zero = 0;
			data->less = 1;
		}
//		ft_putstr("\n\ntest");
//		ft_putchar(str[data->i]);
//		ft_putstr("\n\n");
		ft_detect_width(str, data, data->choice);
		data->i++;
		ft_detect_flags(str, data);
	}
	return (str);
}

char			*ft_detect_width(char *str, t_docker *data, int who)
{
	static int	result = 0;

	if (str[data->i] >= '0' && str[data->i] <= '9')
	{
		result = result * 10 + (str[data->i] - 48);
		if (who == -1)
			data->width  = result;
		else if (who == 1 || who == 0)
		{
			data->dot = 1;
			data->precision = result;
		}
//		ft_putstr("\nnb\n");
//		ft_putnbr(result);
//		ft_putstr("\nchar\n");
//		ft_putchar(str[data->i]);
//		ft_putstr("\n\n");
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
