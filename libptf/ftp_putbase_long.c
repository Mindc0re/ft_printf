/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 08:57:17 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/03 09:02:15 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putbase_long(long int n, long int base)
{
	int len;

	len = 0;
	if (base > 0 && base <= 10)
	{
		if (n >= base)
			len += ftp_putbase_long((n / base), base);
		ft_putchar((n % base) + '0');
		len++;
	}
	return (len);
}
