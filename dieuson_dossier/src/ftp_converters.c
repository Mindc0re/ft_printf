/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_converters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:10:41 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/27 10:02:18 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ftp_putstr(char const *s)
{
    write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

int			ftp_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			ftp_putnbr(int n)
{
    int		len;

    len = 0;
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return (11);
    }
    else
    {
        if (n < 0)
        {
            write(1, "-", 1);
            n = -n;
            len++;
        }
        if (n > 9)
            len += ftp_putnbr(n / 10);
        ft_putchar((n % 10) + '0');
        len++;
    }
    return (len);
}

int			ftp_putbase(unsigned int n, unsigned int base, char letter)
{
    int		len;

    len = 0;
    if (base > 0 && base <= 10)
    {
        if (n >= base)
            len += ftp_putbase((n / base), base, letter);
        ft_putchar((n % base) + '0');
        len++;
    }
    else if (base == 16)
    {
        if (n >= 16)
        {
            len += ftp_putbase((n / 16), base, letter);
            n %= 16;
        }
        if ((n % 16) >= 10)
            ft_putchar((n % 10) + letter);
        else
            ft_putchar((n % 16) + '0');
        len++;
    }
    return (len);
}
