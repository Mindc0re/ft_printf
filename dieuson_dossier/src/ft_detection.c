/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:15:49 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/28 14:41:26 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_detection.h"

char			*ft_detect_flags(char **str, t_form *form)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+' || **str == ' ')
	{
		if (**str == '#')
			form->dieze = 1;
		if (**str == '0')
			form->zero = 1;
		if (**str == '-')
		{
			form->zero = 0;
			form->less = 1;
		}
		if (**str == '+')
			form->more = 1;
		if (**str == ' ')
			form->space = 1;
		(*str)++;
		ft_detect_flags(str, form);
	}
	return (*str);
}

char			*ft_detect_length(char **str, t_form *form)
{
	if (**str == 'h' && *(*str + 1) != 'h')
		form->length = h;
	if (**str == 'h' && *(*str + 1) == 'h')
	{
		form->length = hh;
		(*str) += 2;
	}
	if (**str == 'l' && *(*str + 1) != 'l')
		form->length = l;
	if (**str == 'l' && *(*str + 1) == 'l')
	{
		form->length = ll;
		(*str) += 2;
	}
	if (**str == 'j')
		form->length = j;
	if (**str == 'z')
		form->length = z;
	return (*str);
}

char			*ft_detect_type(char **str, t_form *form, va_list arguments)
{
	if (**str == 's' || **str == 'S' || **str == 'p' || **str == 'd' ||
		**str == 'D'|| **str == 'i' || **str == 'o' || **str == 'O' ||
		**str == 'u'|| **str == 'U' || **str == 'x' || **str == 'X' ||
		**str == 'c' || **str == 'C')
	{
		if (**str == 'i' || **str == 'd')
			ftp_int(str, form, va_arg(arguments, int));
	}
	(*str)++;
	return (*str);
}
