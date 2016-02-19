/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:00:37 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/19 14:17:41 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_putwstr(wchar_t *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_putwchar(str[i]);
		i++;
	}
	return (len);
}
