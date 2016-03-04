/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:54:43 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/03 15:47:41 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_valid(const char *str, t_docker *data)
{
//	if (ft_strchr("sSpdDioOuUxXcC", str[data->i]))
	if (str[data->i] == 's' || str[data->i] == 'S' || str[data->i] == 'p'
		|| str[data->i] == 'd' || str[data->i] == 'D' || str[data->i] == 'i'
		|| str[data->i] == 'o' || str[data->i] == 'O' || str[data->i] == 'u'
		|| str[data->i] == 'U' || str[data->i] == 'x' || str[data->i] == 'X'
		|| str[data->i] == 'c' || str[data->i] == 'C')
		return (1);
	else
		return (0);
}
