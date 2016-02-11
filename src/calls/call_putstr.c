/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:40:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/11 08:45:26 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int					ft_add_spaces(int nb_spaces, int len, char c)
{
	if (nb_spaces > 0)
	{
		while (nb_spaces > 0)
		{
			write(1, &c, 1);
			nb_spaces--;
			len++;
		}
	}
	return (len);
}

int					ftp_dot(uint8_t *str, unsigned int len)
{
	int				i;

	i = 0;
	while (str[i] && i < ftp_strlen(str) && i < (int)len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int					ftp_distrib(t_docker *data, uint8_t *str, int len, int who)
{
	int				ref;

	ref = len;
	if (who == -1)
	{
		len += ftp_putstr(str);
		return (len = ft_add_spaces((data->width - ftp_strlen(str)), len, ' '));
	}
	else if (who == 0)
		return (len += ftp_dot(str, data->precision));
	else if (who == 1)
	{
		len += ftp_dot(str, data->precision);
		return (len = ft_add_spaces((data->width - (len - ref)), len, ' '));
	}
	else if (who == 2)
	{
		if ((len = ft_add_spaces(data->width - (ftp_strlen(str) >
		data->precision ? data->precision : ftp_strlen(str)), len, ' ')) >= 0)
			return (len += ftp_dot(str, data->precision));
	}
	else if (who == 3)
		len = ft_add_spaces((data->width - ftp_strlen(str)), len, ' ');
	return (len += ftp_putstr(str));
}

int					call_putstr(char *str, va_list args, t_docker *data)
{
	uint8_t			*argument;

	argument = va_arg(args, uint8_t *);
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
