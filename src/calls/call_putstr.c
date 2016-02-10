/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:40:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/10 11:26:53 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int					add_spaces(int nb_spaces, int len)
{
	if (nb_spaces > 0)
	{
		while (nb_spaces > 0)
		{
			write(1, " ", 1);
			nb_spaces--;
			len++;
		}
	}
	return (len);
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

int					ftp_distrib(t_docker *data, char *str, int len, int who)
{
	int				ref;

	ref = len;
	if (who == -1)
	{
		len += ftp_putstr((uint8_t *)str);
		return (len = add_spaces((data->width - ft_strlen(str)), len));
	}
	else if (who == 0)
		return (len += ftp_dot(str, data->precision));
	else if (who == 1)
	{
		len += ftp_dot(str, data->precision);
		return (len = add_spaces((data->width - (len - ref)), len));
	}
	else if (who == 2)
	{
		len = add_spaces((data->width - ft_strlen(str)), len);
		return (len += ftp_dot(str, data->precision));
	}
	else if (who == 3)
		len = add_spaces((data->width - ft_strlen(str)), len);
	return (len += ftp_putstr((uint8_t *)str));
}

int					call_putstr(char *str, va_list args, t_docker *data)
{
	char			*argument;

	argument = va_arg(args, char *);
	if (data->width >= 1 && data->dot == 0 && data->less == 0)
		data->len = ftp_distrib(data, argument, data->len, 3);
	else if (data->dot == 1 && data->less == 1)
		data->len = ftp_distrib(data, argument, data->len, 1);
	else if (data->less == 1 && str && data->dot == 0)
		data->len = ftp_distrib(data, argument, data->len, -1);
	else if (data->width >= 1 && data->dot == 1 && data->less == 0)
		data->len = ftp_distrib(data, argument, data->len, 2);
	else if (data->dot == 1 && data->less == 0 && data->width == 0)
		data->len = ftp_distrib(data, argument, data->len, 0);
	else
		data->len = ftp_distrib(data, argument, data->len, 4);
	return (0);
}
