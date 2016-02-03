/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:18:56 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/02 11:00:28 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		FT_DETECTION_H
# define	FT_DETECTION_H

typedef	struct		s_form
{
	int				dieze;
	int				zero;
	int				less;
	int				more;
	int				space;
	int				dot;
	char			type;
	int				width;
	int				precision;
	int				i;
	enum {
					h,
					hh,
					l,
					ll,
					j,
					z
	}				length;
}					t_form;

char				*ftp_detect_width(char **str, t_form *form, int val);
char				*ft_detect_length(char **str, t_form *form);
char				*ft_detect_flags(char **str, t_form *form);

#endif


















