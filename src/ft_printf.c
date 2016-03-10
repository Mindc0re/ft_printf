/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:51:01 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/10 09:39:48 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

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
	data->fct['p'] = &call_putadress;
	data->fct['%'] = &call_purcent;
	return (data);
}

void		init_structure(t_docker *data, int check)
{
	if (check == 1)
	{
		data->i = 0;
		data->len = 0;
	}
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

int			parser(va_list args, const char *str, t_docker *data)
{
		ft_detect_flags(str, data);
		detect_conversion(str, data);
		data->type = str[data->i];
		if (ft_check_valid(str, data) == 1)
			return ((*data->fct[(int)str[data->i]])(str, args, data));
		else
			return (ftp_putchar((uint8_t)str[data->i]));
	return (0);
}

int			detect(const char *s, t_docker *data)
{
	data->i++;
	if ((s[data->i] == ' ' && s[data->i + 1] == ' ')
		|| (s[data->i] == ' ' && s[data->i + 1] == '%'))
	{
		while (s[data->i] != '\0' && s[data->i] == ' ')
			data->i++;
		if (s[data->i] == '%')
			return (1);
	}
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

int			ft_check_printf(const char *s, t_docker *data)
{
	while (s[data->i] && data->i < ft_strlen(s))
	{
		if (s[data->i] != '%')
			data->i++;
		else
		{
			if (detect(s, data))
			{
				ft_detect_flags(s, data);
				detect_conversion(s, data);
				data->type = s[data->i];
				if (!ft_check_valid(s, data) && !ft_strchr("h ", s[data->i - 1]))
					if (s[data->i] != '%')
						return (0);
			}
			init_structure(data, 0);
			data->i = (s[data->i == '\0'] ? data->i + 1 : data->i);
		}
	}
	init_structure(data, 1);
	data->len = 0;
	data->i = 0;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_docker	*data;

	data = init_tabptr();
	init_structure(data, 1);
	va_start(args, format);
	if (!ft_check_printf(format, data))
		return (0);
	while (format[data->i] && data->i < ft_strlen(format))
	{
		if (format[data->i] != '%' && format[data->i] != '\0')
		{
			data->len += ftp_putchar((uint8_t)format[data->i]);
			data->i++;
		}
		else
		{
			if (detect(format, data))
				data->len += parser(args, format, data);
			else
				data->len += ftp_putchar((uint8_t)format[data->i]);
			init_structure(data, 0);
			data->i = (format[data->i == '\0'] ? data->i + 1 : data->i);
		}
	}
	va_end(args);
	return (data->len);
}
