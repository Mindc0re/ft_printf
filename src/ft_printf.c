/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:51:01 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/11 17:30:32 by sgaudin          ###   ########.fr       */
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
	data->wide_width = 0;
}

int			parser(va_list args, const char *str, t_docker *data)
{
		ft_detect_flags(str, data);
		detect_conversion(str, data);
		data->type = str[data->i];
		if (ft_check_valid(str, data) == 1)
			return ((*data->fct[(int)str[data->i]])(str, args, data));
		else if (!ft_strchr("sSpdDioOuUxXcC hljz", str[data->i]))
			return ((*data->fct['%'])(str, args, data));
		else
			return (0);
}

int			ft_check_printf(const char *s, t_docker *data)
{
	while (s[data->i] && data->i < (int)ft_strlen(s))
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
				if (!ft_check_valid(s, data))
					if (s[data->i] != '%' && data->length)
						return (0);
			}
			init_structure(data, 0);
			data->i = (s[data->i == '\0'] ? data->i + 1 : data->i);
		}
	}
	init_structure(data, 1);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;

	FT_INIT(t_docker *, data, init_tabptr());
	FT_INIT(int, ret, 0);
	init_structure(data, 1);
	va_start(args, format);
	if (!ft_check_printf(format, data))
		return (0);
	while (format[data->i] && data->i < (int)ft_strlen(format))
	{
		if (format[data->i] != '%' && format[data->i] != '\0')
		{
			data->len += ftp_putchar((uint8_t)format[data->i]);
			data->i++;
		}
		else
		{
			if (!format[data->i + 1])
				break;
			if (detect(format, data))
				data->len += parser(args, format, data);
			else
				data->len += ftp_putchar((uint8_t)format[data->i]);
			init_structure(data, 0);
			data->i = (format[data->i == '\0'] ? data->i + 1 : data->i);
		}
	}
	printf("NTM1\n");
	ret = data->len;
	printf("NTM2\n");
	va_end(args);
	printf("NTM3\n");
	ft_memdel((void **)&data);
	printf("NTM4\n");
	return (ret);
}
