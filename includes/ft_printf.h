/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:55:34 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/29 14:59:25 by sgaudin          ###   ########.fr       */
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
	int				len;
	int				(*ptr_fct[256])(char *, int, va_list);
}					t_docker;

int			ftp_flag_hh(char *str, t_docker *data, va_list pointeur);
int			ftp_flag_hh_i(char c, t_docker *data);
int			ftp_flag_hh_o(unsigned char u, t_docker *data);
int			ftp_flag_hh_u(unsigned char u, t_docker *data);
int			ftp_flag_x(unsigned char u, t_docker *data, char letter);

int			ftp_putbase(uint32_t n, uint32_t base, uint8_t flag);
int			ftp_putchar(uint32_t c);
int			ftp_putstr(uint8_t *str);
int			ftp_strlen(uint8_t *str);
int			ftp_putnbr(int32_t n);

#endif


