/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:55:34 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/28 09:40:55 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PRINTF_H
# define	FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include "ft_detection.h"

typedef struct		s_docker
{
	int				i;
}					t_docker;

int			ftp_flag_hh(char *str, t_docker *data, va_list pointeur);
int			ftp_flag_hh_i(char c, t_docker *data);
int			ftp_flag_hh_o(unsigned char u, t_docker *data);
int			ftp_flag_hh_u(unsigned char u, t_docker *data);
int			ftp_flag_x(unsigned char u, t_docker *data, char letter);

int			ftp_putchar(char c);
int			ft_printf_putstr(char const *s);
int			ft_compare(char *str, va_list pointeur, t_docker *data);
int			ft_printf_putnbr_base(int n, int base);
int			ftp_putbase(unsigned int n, unsigned int base, char letter);
int			ftp_putnbr(int n);
int			ftp_putstr(char const *s);

#endif
