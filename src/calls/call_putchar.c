/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:53:50 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/19 09:16:39 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putchar(const char *str, va_list args, t_docker *data)
{
	if (data->length == l)
		return (ft_putwchar(va_arg(args, wint_t)));
	if (str[data->i] == 'c')
	{
		if (data->width > 0 && data->less == 0)
			data->len = ft_add_spaces(data->width - 1, data->len, ' ');
		return (ftp_putchar(va_arg(args, uint32_t)));
	}
	else
		return (0);
}
