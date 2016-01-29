/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:38:00 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/29 14:02:59 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
#include <stdarg.h>

typedef struct		s_printf
{
	int				(*ptr_fct[256])(char *, int, va_arg);
	enum
	{
		h,
		hh,
		l,
		ll,
		j,
		z
	}				modifier;
}					t_printf;

#endif
