/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:58:24 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/15 15:33:08 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		putbase_part2(t_docker *data, uint32_t result, int base, uint8_t flag)
{
	FT_INIT(int, prec, 0);
	FT_INIT(int, length, 0);
	if (data->dot == 1)
	{
		data->len += (length == 0 || length == 1 ) ? longueur_nb(result) : 0;
		length = data->precision - longueur_nb(result);
		prec = data->len;
		data->len = ft_add_spaces(length, data->len, '0');
	}
	if (data->less == 1)
	{
		length = data->width - longueur_nb(result);
		length -= prec != 0 ? (data->len - prec) : 0;
		data->len += prec != 0 ? 0 : longueur_nb(result);
		ftp_putbase(result, base, flag, data->dieze);
		data->len = ft_add_spaces(length, data->len, ' ');
		return (0);
	}
	if (data->less == 0 && data->dot == 0 && data->width == 0)
		data->len += longueur_nb(result);
	return (1);
}

int		distrib_putbase(t_docker *data, uint32_t result, int base, uint8_t flag)
{
	FT_INIT(int, length, 0);
	FT_INIT(int, len_nb, longueur_nb(result));
	if (data->dieze == 1 && flag == 'a')
		data->len += ftp_putstr((uint8_t *)"0x");
	else if (data->dieze == 1 && flag == 'A')
		data->len += ftp_putstr((uint8_t *)"0X");
	if (data->less == 0 && data->width > 0)
	{
		if (data->dot == 1)
			if (data->precision - len_nb)
				length -= data->precision - len_nb;
		length += data->width - len_nb;
		data->len += len_nb;
		data->len = ft_add_spaces(length, data->len,
		(data->zero == 1 && data->dot == 0 ? '0' : ' '));
	}
	if (putbase_part2(data, result, base, flag) == 0)
		return (0);
	ftp_putbase(result, base, flag, data->dieze);
	return (0);
}

int		call_putbase(char *str, va_list args, t_docker *data)
{
	int result;

	result = va_arg(args, uint32_t);
	if (str[data->i] == 'u')
		return (distrib_putbase(data, result, 10, 'a'));
	else if (str[data->i] == 'o')
		return (distrib_putbase(data, result, 8, 'a'));
	else if (str[data->i] == 'x')
		return (distrib_putbase(data, result, 16, 'a'));
	else if (str[data->i] == 'X')
		return (distrib_putbase(data, result, 16, 'A'));
	else
		return (0);
}

