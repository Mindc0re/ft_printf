/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:18:19 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/29 11:36:46 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

int			ftp_putbase(uint32_t n, uint32_t base, uint8_t flag);
int			ftp_putchar(uint32_t c);
int			ftp_putstr(uint8_t *str);
int			ftp_strlen(uint8_t *str);
int			ftp_putnbr(int32_t n);

#endif
