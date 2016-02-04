/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:40:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 17:50:10 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int			ftp_less(int len_str, char *str, int choice, int dimension)
{
	unsigned int nb_spaces;

//	ft_putstr("\ndimension\n");
//	ft_putnbr(dimension);
//	ft_putstr("\n\n");
	nb_spaces = dimension - ft_strlen(str);
	if (choice == -1)
		write(1, str, ft_strlen(str));
	else if (choice == 0)
		return (len_str += ftp_putstr((uint8_t *)str));
	if (nb_spaces > 0)
	{
		while (nb_spaces > 0)
		{
			write(1, " ", 1);
			nb_spaces --;
			len_str++;
			}
	}
	if (choice == 1)
		write(1, str, ft_strlen(str));
	return (len_str + ft_strlen(str));
}

int					ftp_dot(char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < ft_strlen(str) && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int					call_putstr(char *str, va_list args, t_docker *data)
{
	char			*argument;

	argument = va_arg(args, char *);
//	ft_putstr("\nwidth\n\n");
//	ft_putnbr(data->width);
//	ft_putstr("\n\n");
//	ft_putstr("\nprecision\n\n");
//	ft_putnbr(data->precision);
//	ft_putstr("\n\n");
	if (data->less == 1 && str)
		data->len = ftp_less(data->len, argument, -1, data->width);
	else if (data->precision > 0  && data->less == 0 && data->dot == 0)
		data->len = ftp_less(data->len, argument, 1, data->precision);
	else if (data->dot == 1)
		return (ftp_dot(argument, data->precision));
	else
		data->len = ftp_less(data->len, argument, 0, 0);
	return (0);
}
