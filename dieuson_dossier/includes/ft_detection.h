/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:56 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/29 14:39:50 by sgaudin          ###   ########.fr       */
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
					h,
					hh,
					l,
					ll,
					j,
					z
	}				length;
}					t_form;
char				*ft_detect_length(char **str, t_form *form);
char				*ft_detect_flags(char **str, t_form *form);

#endif
