/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:53:50 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 16:08:57 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putchar(const char *str, va_list args, t_docker *data)
{
//	FT_INIT(int,spaces,-1);

//	if (data->width > 0 && data->less == 0)
//		spaces += ft_add_spaces((data->width - 1), 1, (data->zero == 1 ? '0' : ' '));
	if (data->length == l)
		return (ft_putwchar(va_arg(args, wint_t)));
	if (str[data->i] == 'c')
		return (ftp_putchar(va_arg(args, uint32_t)));
	else
		return (0);
}
