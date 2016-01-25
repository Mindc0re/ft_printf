/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:35:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/25 12:56:33 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		parser(char *str, int i, va_list args)
{
	int		tmp;

	tmp = 0;
	if (str[i] == 's')
		ft_putstr(va_arg(args, char *));
	if (str[i] == 'c')
	{
		ft_putchar(va_arg(args, char));
		return (1);
	}
	if (str[i] == 'd')
	{
		tmp = (va_arg(args, int));
		ft_putnbr(tmp);
		return (ft_strlen(ft_atoi(tmp)));
	}
	if (str[i] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int		ft_printf(char *str, ...)
{
	va_list args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			len++;
		}
		else
			len += parser(str, i + 1, args);
	}
	return (len);
}

int		main(void)
{
	ft_printf()
	printf("")
	return (0);
}
