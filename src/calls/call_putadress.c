/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:29:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 14:38:37 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			call_putadress(const char *str, va_list args, t_docker *data)
{
	FT_INIT(uint32_t,result,va_arg(args, uint32_t));
	FT_INIT(int,len,0);

	if (str[data->i] == 'p')
	{
		ft_putstr("0x7fff");
		len += 2;
		len += ftp_putbase(result, 16, 'a', data->dieze);
	}
	return (len);
}
