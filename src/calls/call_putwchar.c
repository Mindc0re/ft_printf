/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:38:25 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/15 17:41:31 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		call_putwchar(char *str, va_list args, t_docker *data)
{
	if (str[data->i] == 'C')
		return (ft_putwchar(va_arg(args, wchar_t)));
	else
		return (0);
}
