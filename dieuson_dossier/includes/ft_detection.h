/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:56 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/28 15:22:38 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_DETECTION_H
# define	FT_DETECTION_H
# include "libft.h"
# include <stdarg.h>

typedef	struct		s_form
{
	int				dieze;
	int				zero;
	int				less;
	int				more;
	int				space;
	char			type;

	enum {
		h ,
		hh,
		l,
		ll,
		j,
		z
	} length;
}					t_form;
char				*ft_detect_type(char **str, t_form *form, va_list arguments);
char				*ft_detect_length(char **str, t_form *form);
char				*ft_detect_flags(char **str, t_form *form);
int					ftp_int(char **str, t_form *form, int nb);

#endif


















