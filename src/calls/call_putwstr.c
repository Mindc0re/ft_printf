/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:40:51 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/08 17:41:49 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putwstr(char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 'S')
		return (ft_putwstr(va_arg(args, wchar_t *)));
	else
		return (0);
}
