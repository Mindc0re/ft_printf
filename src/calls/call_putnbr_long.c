/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:02:53 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 17:54:05 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			call_putnbr_long(char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 'D')
		return(ftp_putnbr_long(va_arg(args, long int), data->space, data->more));
	else
		return (0);
}
