/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:35:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/01 18:07:33 by sgaudin          ###   ########.fr       */
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
}


int		parser(char c, va_list args, char *str, t_docker *data)
{
	if (c == '%')
		return (ftp_putchar('%'));
	else
		return ((*data->fct[(int)c])(str, args, data));
	return (0);
}
/*
int		parser(char c, va_list args, char *str, t_docker *data)
{
	if (c == 's')
		return ((*data->fct[(int)c])(str, args, data));
//		return(call_putstr(str, args, data));
//		return (ftp_putstr(va_arg(args, uint8_t *)));
	else if (c == 'd' || c == 'i')
		return (ftp_putnbr(va_arg(args, uint32_t)));
	else if (c == 'c')
		return (ftp_putchar((uint8_t)va_arg(args, uint32_t)));
	else if (c == 'u')
		return (ftp_putbase(va_arg(args, uint32_t), 10, 0));
	else if (c == 'o')
		return (ftp_putbase(va_arg(args, uint32_t), 8, 0));
	else if (c == 'x')
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'a'));
	else if (c == 'X')
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'A'));
	else if (c == 'p')
	{
		ft_putstr("0x7fff");
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'a'));
	}
	else if (c == '%')
		return (ftp_putchar('%'));
	return (0);
}
*/
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

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;

	ret_ft = ft_printf("FT_PRINTF : Coucou je suis %s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %x et %X\n", "Simon", 17, 'Q', 500, 500);
	ret = printf("   PRINTF : Coucou je suis %s et j'ai %d ans, ceci est la lettre %c et voici 500 en hexadecimal : %x et %X\n", "Simon", 17, 'Q', 500, 500);
	printf("Printf retourne %d caracteres, et ft_printf retourne %d caracteres\n", ret, ret_ft);

//	printf("\n   PRINTF : Test adresse de ret : %p", &ret);
//	ft_printf("\nFT_PRINTF : Test adresse de ret : %p\n", &ret);

	return (0);
}
