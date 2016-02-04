/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:53:50 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 10:45:50 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putchar(char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 'c')
		return (ftp_putchar(va_arg(args, uint32_t)));
	else
	return (0);
}
