/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:29:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 14:53:11 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			call_putadress(const char *str, va_list args, t_docker *data)
{
	FT_INIT(uint32_t,result,va_arg(args, uint32_t));
	FT_INIT(int,len,0);

	if (str[data->i] == 'p')
	{
		ft_putstr((!result ? "0x" : "0x7fff"));
		len += !result ? 2 : 6;
		len += ftp_putbase(result, 16, 'a', data->dieze);
	}
	return (len);
}
