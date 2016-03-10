/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:18:19 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/10 10:40:52 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../includes/ft_printf.h"
# include <stdarg.h>
# include <wchar.h>

int			ftp_putbase(uintmax_t n, uint32_t base, uint8_t flag,
						t_docker *data);
int			ftp_putchar(uint32_t c);
int			ftp_putstr(uint8_t *str);
int			ftp_strlen(uint8_t *str);
int			ftp_putnbr(int64_t n, t_docker *data);
int			ftp_putnbr_long(int64_t n, t_docker *data);
int			ftp_putbase_long(uintmax_t n, uint32_t base, uint8_t flag,
							t_docker *data);

#endif
