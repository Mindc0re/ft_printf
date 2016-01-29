/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:34:26 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/28 16:26:15 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_detection.h"

int			ftp_int(char **str, t_form *form, int nb)
{
	if (form->more)
		if (nb > 0)
			ft_putchar('+');
	str = NULL;
	ftp_putnbr(nb);
	return(0);
}
