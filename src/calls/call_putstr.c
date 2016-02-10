/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:40:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/10 14:43:51 by dvirgile         ###   ########.fr       */
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
		return (len = ft_add_spaces((data->width - ft_strlen(str)), len, ' '));
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
		len = ft_add_spaces(data->width - ((int)ft_strlen(str) > data->precision ? data->precision : ft_strlen(str)), len, ' ');
		return (len += ftp_dot(str, data->precision));
	}
	else if (who == 3)
		len = ft_add_spaces((data->width - ft_strlen(str)), len, ' ');
	return (len += ftp_putstr((uint8_t *)str));
}

int					call_putstr(char *str, va_list args, t_docker *data)
{
	char			*argument;

/*	ft_putstr("\n\nWidth\n");
	ft_putnbr(data->width);
	ft_putstr("\nWidth\n");
	ft_putstr("\n\nprecision\n");
	ft_putnbr(data->precision);
	ft_putstr("\nprecision\n\n");*/
	argument = va_arg(args, char *);
	if (data->width >= 1 && data->dot == 0 && data->less == 0) // un nombre
		data->len = ftp_distrib(data, argument, data->len, 3);
	else if (data->dot == 1 && data->less == 1) // un '-' et un '.'
		data->len = ftp_distrib(data, argument, data->len, 1);
	else if (data->less == 1 && str && data->dot == 0) // un '-'
		data->len = ftp_distrib(data, argument, data->len, -1);
	else if (data->width >= 1 && data->dot == 1 && data->less == 0) // un chiffre et un '.'
		data->len = ftp_distrib(data, argument, data->len, 2);
	else if (data->dot == 1 && data->less == 0 && data->width == 0) // un '.'
		data->len = ftp_distrib(data, argument, data->len, 0);
	else
		data->len = ftp_distrib(data, argument, data->len, 4); //juste s
	return (0);
}
