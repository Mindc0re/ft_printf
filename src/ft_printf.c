/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:19:18 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/11 17:51:38 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>

t_docker	*init_tabptr(void)
{
	t_docker *data;

	data = (t_docker *)malloc(sizeof(data));
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
	data->fct['C'] = &call_putwchar;
	data->fct['S'] = &call_putwstr;
	return (data);
}

void		init_structure(t_docker *data)
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
	data->choice = 0;
	data->result = 0;
}

int			parser(va_list args, char *str, t_docker *data)
{
	if (str[data->i] == '%')
		return (ftp_putchar('%'));
	else
	{
		ft_detect_flags(str, data);
		ft_detect_length(str, data);
		return ((*data->fct[(int)str[data->i]])(str, args, data));
	}
	return (0);
}

int			detect(char *s, t_docker *data)
{
	data->i++;
	if (s[data->i] == 's' || s[data->i] == 'S' || s[data->i] == 'p'
		|| s[data->i] == 'd' || s[data->i] == 'D' || s[data->i] == 'i'
		|| s[data->i] == 'o' || s[data->i] == 'O' || s[data->i] == 'u'
		|| s[data->i] == 'U' || s[data->i] == 'x' || s[data->i] == 'X'
		|| s[data->i] == 'c' || s[data->i] == 'C' || s[data->i] == '%'
		|| s[data->i] == '#' || s[data->i] == '0' || s[data->i] == '-'
		|| s[data->i] == '+' || s[data->i] == 'h' || s[data->i] == 'l'
		|| s[data->i] == 'j' || s[data->i] == 'z' || s[data->i] == '.'
		|| (s[data->i] >= '0' && s[data->i] <= '9')
		|| (s[data->i] == ' ' && s[data->i - 1] == '%'))
		return (1);
	else
		return (0);
}

int			ft_printf(char *str, ...)
{
	va_list		args;
	t_docker	*data;

	data = init_tabptr();
	data->i = 0;
	data->len = 0;
	init_structure(data);
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
				data->len += parser(args, str, data);
			init_structure(data);
			data->i += 1;
		}
	}
	return (data->len);
}
