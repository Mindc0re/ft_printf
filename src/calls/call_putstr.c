/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:40:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/01 18:10:17 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putstr(char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 's')
		return (ftp_putstr(va_arg(args, uint8_t *)));
	else
		return (0);
}
