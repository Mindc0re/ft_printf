/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:29:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/02 14:47:19 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		adresse_part2(t_docker *data, uint32_t result, int base, uint8_t flag)
{
	FT_INIT(int, prec, 0);
	FT_INIT(int, length, data->less == 0 && data->width > 0 ? 1 : 0);
	FT_INIT(int, len_nb, len_base(result, base));
	if (data->dot == 1)
	{
		data->len += (length == 0) ? len_nb : 0;
		length = data->precision - len_nb;
		prec = data->len;
		data->len = ft_add_spaces(length, data->len, '0');
	}
	if (data->less == 1)
	{
		ft_putstr((!result ? "0x" : "0x7fff"));
		length = data->width - len_nb - (!result ? 2 : 6);
		length -= prec != 0 ? (data->len - prec) : 0;
		data->len += prec != 0 ? 0 : len_nb;
		ftp_putbase(result, base, flag, data->dieze);
		data->len = ft_add_spaces(length, data->len, ' ');
		return (0);
	}
	if (data->less == 0 && data->dot == 0 && data->width == 0)
	{
		ft_putstr((!result ? "0x" : "0x7fff"));
		data->len += len_nb + (data->dieze == 1 ? 2 : 0);
	}
	return (1);
}

int		distrib_adresse(t_docker *data, uint32_t result, int base, uint8_t flag)
{
	FT_INIT(int, length, 0 - (!result ? 2 : 6));
	FT_INIT(int, len_nb, len_base(result, base));
	if (data->less == 0 && data->width > 0)
	{
		if ((data->precision - len_nb) > 0)
			length -= data->precision - len_nb;
		length += data->width - len_nb - (data->dieze == 1 ? 2 : 0);
		data->len += len_nb + (data->dieze == 1 ? 2 : 0);
		data->len = ft_add_spaces(length, data->len, (data->zero == 1 ?
													  '0' : ' '));
		ft_putstr((!result ? "0x" : "0x7fff"));
	}
	if (adresse_part2(data, result, base, flag) == 0)
		return (0);
	ftp_putbase(result, base, flag, data->dieze);
	return (0);
}

int			call_putadress(const char *str, va_list args, t_docker *data)
{
	FT_INIT(uint32_t,result,va_arg(args, uint32_t));
	FT_INIT(int,len,0);

/*	if (str[data->i] == 'p')
	{
		ft_putstr((!result ? "0x" : "0x7fff"));
		len += !result ? 2 : 6;
		len += ftp_putbase(result, 16, 'a', data->dieze);
	}
*/
	if (str[data->i] == 'p')
	{
		data->len += !result ? 2 : 6;
		return (distrib_adresse(data, result, 16, 'a'));
	}
	return (len);
}
