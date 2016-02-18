/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:38:25 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 10:00:13 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putwchar(const char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 'C')
		return (ft_putwchar(va_arg(args, wchar_t)));
	else
		return (0);
}
