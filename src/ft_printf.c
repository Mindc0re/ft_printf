/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:35:55 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/29 14:15:59 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libptf/libftprintf.h"
#include <stdio.h>
#include <math.h>

t_printf	*init_tab_ptr(void)
{
	static t_printf	*list_ptf = NULL;
	if (!list_ptf)
	{
		list_ptf = (t_printf*)malloc(sizeof(*list_ptf));
	}
	return (list_ptf);
}

int		parser(char *str, int i, va_list args)
{
	int		tmp;

	tmp = 0;
	if (str[i] == 's')
		return (ftp_putstr(va_arg(args, uint8_t *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ftp_putnbr(va_arg(args, uint32_t)));
	else if (str[i] == 'c')
		return (ftp_putchar((uint8_t)va_arg(args, uint32_t)));
	else if (str[i] == 'u')
		return (ftp_putbase(va_arg(args, uint32_t), 10, 0));
	else if (str[i] == 'o')
		return (ftp_putbase(va_arg(args, uint32_t), 8, 0));
	else if (str[i] == 'x')
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'a'));
	else if (str[i] == 'X')
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'A'));
	else if (str[i] == 'p')
	{
		ft_putstr("0x7fff");
		return (ftp_putbase(va_arg(args, uint32_t), 16, 'a'));
	}
	else if (str[i] == '%')
		return (ftp_putchar('%'));
	return (0);
}

int		detect(char *s, int *i)
{
	*i= *i + 1;
	if (s[*i] == 's' || s[*i] == 'S' || s[*i] == 'p' || s[*i] == 'd'
		|| s[*i] == 'D' || s[*i] == 'i' || s[*i] == 'o' || s[*i] == 'O'
		|| s[*i] == 'u' || s[*i] == 'U' || s[*i] == 'x' || s[*i] == 'X'
		|| s[*i] == 'c' || s[*i] == 'C' || s[*i] == '%' || s[*i] == '#'
		|| s[*i] == '0' || s[*i] == '-' || s[*i] == '+' || s[*i] == 'h'
		|| s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z')
		return (1);
	else
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
		{
			if (detect(str, &i))
				len += parser(str, i, args);
			else
				i++;
		}
		i++;
	}
	return (len);
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
