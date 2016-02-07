/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 15:23:59 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/07 16:55:25 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "../libftprintf/libftprintf.h"

#define MASK_1 "0xxxxxxx"
#define MASK_2 "110xxxxx 10xxxxxx"
#define MASK_3 "1110xxxx 10xxxxxx 10xxxxxx"
#define MASK_4 "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"

char		**set_mask(char *bin_value, char *mask_macro)
{
	char	*mask;
	int		size;
	int		i;

	mask = ft_strdup(mask_macro);
	size = ft_strlen(mask) - 1;
	i = 0;
	while (size >= 0)
	{
		if (mask[size] == 'x')
		{
			mask[size] = bin_value[i];
			i++;
		}
		size--;
	}
	i = 0;
	while (mask[i])
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i++;
	}
	return (ft_strsplit(mask, ' '));
}

int			ft_putwchar(wchar_t c)
{
	char	*bin_value;
	char	**final;
	int		i;

	bin_value = ft_itoa_base((int)c, 2);
	if (ft_strlen(bin_value) <= 7)
		return (ftp_putchar((char)c));
	else if (ft_strlen(bin_value) <= 11)
		final = set_mask(bin_value, MASK_2);
	else if (ft_strlen(bin_value) > 11 && ft_strlen(bin_value) <= 16)
		final = set_mask(bin_value, MASK_3);
	else
		final = set_mask(bin_value, MASK_4);
	ft_memdel((void **)&bin_value);
	i = 0;
	return (1);
}
