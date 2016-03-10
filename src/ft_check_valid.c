/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:54:43 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/09 11:04:18 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_valid(const char *str, t_docker *data)
{
	if (ft_strchr("sSpdDioOuUxXcC%", str[data->i]) && str[data->i])
		return (1);
	else
		return (0);
}
