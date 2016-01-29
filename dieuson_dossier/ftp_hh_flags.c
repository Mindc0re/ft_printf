/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_hh_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:16:20 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/26 11:16:22 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int						ftp_flag_hh(char *str, t_docker *data, va_list pointeur)
{
	if (str[0] == 'i' || str[0] == 'd')
		return (ftp_flag_hh_i(va_arg(pointeur, int), data));
	if (str[0] == 'o')
		return (ftp_flag_hh_o(va_arg(pointeur, unsigned int), data));
	if (str[0] == 'u')
		return (ftp_flag_hh_u(va_arg(pointeur, unsigned int), data));
	if (str[0] == 'x')
		return (ftp_flag_x(va_arg(pointeur, unsigned int), data, 'a'));
	if (str[0] == 'X')
		return (ftp_flag_x(va_arg(pointeur, unsigned int), data, 'A'));
	return (0);
}

int						ftp_flag_hh_i(char c, t_docker *data)
{
	int					nb;

	nb = (int)c;
	data->i += 2;
	return (ftp_putnbr(nb));
}

int						ftp_flag_hh_o(unsigned char u, t_docker *data)
{
	unsigned int		nb;

	nb = (unsigned int)u;
	data->i += 2;
	return (ftp_putbase(nb, 8, 'a'));
}

int						ftp_flag_hh_u(unsigned char u, t_docker *data)
{
	unsigned int		nb;

	nb = (unsigned int)u;
	data->i += 2;
	return (ftp_putbase(nb, 10, 'a'));
}

int						ftp_flag_x(unsigned char u, t_docker *data, char letter)
{
	unsigned int		nb;

	nb = (unsigned int)u;
	data->i += 2;
	if (letter == 'a')
		return (ftp_putbase(nb, 16, 'a'));
	else
		return (ftp_putbase(nb, 16, 'A'));
}
