/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:56:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 17:53:55 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putnbr(char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 'd' || str[data->i] == 'i')
		return (ftp_putnbr(va_arg(args, uint32_t), data->space, data->more));
	else
		return (0);
}
