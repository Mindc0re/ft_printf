/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:00:37 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/03 14:10:13 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_putwstr(wchar_t *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] && str != NULL)
	{
		len += ft_putwchar(str[i]);
		i++;
	}
	return (len);
}
