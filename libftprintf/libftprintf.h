/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:18:19 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/12 12:25:37 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

int			ftp_putbase(uint32_t n, uint32_t base, uint8_t flag,
						uint32_t dieze);
int			ftp_putchar(uint32_t c);
int			ftp_putstr(uint8_t *str);
int			ftp_strlen(uint8_t *str);
int			ftp_putnbr(int32_t n, uint32_t space, uint32_t more, int precision);
int			ftp_putnbr_long(long int n, int space, int more);
int			ftp_putbase_long(long int n, long int base, int dieze);

#endif
