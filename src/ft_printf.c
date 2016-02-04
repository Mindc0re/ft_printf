/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:35:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/04 11:43:14 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>

void	init_tabptr(t_docker *data)
{
	data->fct['s'] = &call_putstr;
	data->fct['c'] = &call_putchar;
	data->fct['d'] = &call_putnbr;
	data->fct['i'] = &call_putnbr;
	data->fct['u'] = &call_putbase;
	data->fct['o'] = &call_putbase;
	data->fct['x'] = &call_putbase;
	data->fct['X'] = &call_putbase;
	data->fct['D'] = &call_putnbr_long;
	data->fct['O'] = &call_putbase_long;
	data->fct['U'] = &call_putbase_long;
}

void int_structure(t_docker *data)
{
	data->dieze = 0;
	data->zero = 0;
	data->less = 0;
	data->more = 0;
	data->space = 0;
	data->dot = 0;
	data->width = 0;
	data->precision = 0;
	data->type = 0;
	data->length = 0;
}

int		parser(char c, va_list args, char *str, t_docker *data)
{
	if (c == '%')
		return (ftp_putchar('%'));
	else
	{
		ft_detect_flags(str, data);
		ft_detect_length(str, data);
		return ((*data->fct[(int)c])(str, args, data));
	}
	return (0);
}

int		detect(char *s, t_docker *data)
{
	data->i++;
	if (s[data->i] == 's' || s[data->i] == 'S' || s[data->i] == 'p' || s[data->i] == 'd'
		|| s[data->i] == 'D' || s[data->i] == 'i' || s[data->i] == 'o' || s[data->i] == 'O'
		|| s[data->i] == 'u' || s[data->i] == 'U' || s[data->i] == 'x' || s[data->i] == 'X'
		|| s[data->i] == 'c' || s[data->i] == 'C' || s[data->i] == '%' || s[data->i] == '#'
		|| s[data->i] == '0' || s[data->i] == '-' || s[data->i] == '+' || s[data->i] == 'h'
		|| s[data->i] == 'l' || s[data->i] == 'j' || s[data->i] == 'z')
		return (1);
	else
		return (0);
}

int		ft_printf(char *str, ...)
{
	va_list 	args;
	t_docker	*data;

	data = (t_docker*)malloc(sizeof(data));
	init_tabptr(data);
	data->i = 0;
	data->len = 0;
	va_start(args, str);
	while (str[data->i])
	{
		if (str[data->i] != '%')
		{
			ft_putchar(str[data->i]);
			data->i++;
			data->len++;
		}
		else
		{
			if (detect(str, data))
				data->len += parser(str[data->i], args, str, data);
			data->i += 1;
		}
	}
	return (data->len);
}
