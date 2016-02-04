/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:40:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 10:09:31 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int ftp_less(int nb_spaces)
{
	int len;

	len = 0;
	if (nb_spaces > 0)
	{
		while (nb_spaces > 0)
		{
			write(1, " ", 1);
			nb_spaces --;
			len++;
		}
	}
	return (len);
}

int					ftp_dot(char *str, t_docker *data, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < ft_strlen(str) && i < len)
	{
		data->i++;
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		call_putstr(char **str, va_list args, t_docker *data)
{
	int len;
	char *argument;

	argument = va_arg(args, char *);
	len = data->i;
	if (data->less == 1)
	{
		write(1, argument, ft_strlen(argument));
		data->i += ftp_less((data->width - ft_strlen(argument)));
	}
	else if (data->width >= 0  && data->less == 0)
	{
		data->i += ftp_less((data->width - ft_strlen(argument)));
		write(1, argument, ft_strlen(argument));
	}
	else if (data->dot == 1)
		return (ftp_dot(argument, data, data->precision));
	else
		write(1, argument, ft_strlen(argument));
//	data->i += ft_strlen(argument);
	str += 1;
	return (data->i - len);
/*	if (str[data->i] == 's')
		return (ftp_putstr(va_arg(args, uint8_t *)));
	else
	return (0);*/
}
