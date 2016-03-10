/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:23:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/09 10:35:56 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"

# define FT_INIT(type,name,value)		type name = value
# define TER(si,alors,sinon)			si ? alors : sinon
# define MULTI(val_a, val_b, val_c)		val_a = val_b = val_c
typedef struct		s_docker
{
	int				result;
	int				i;
	int				len;
	int				(*fct[256])(const char *, va_list, struct s_docker *);
	int				dieze;
	int				zero;
	int				less;
	int				more;
	int				space;
	int				dot;
	int				width;
	int				precision;
	char			type;
	int				choice;
	int				length;

	enum {
					hh = 1,
					h,
					ll,
					l,
					j,
					z
	};
}					t_docker;

# include "../libftprintf/libftprintf.h"

int					ft_printf(const char *format, ...);

int					longueur_nb(int64_t nb);
int					len_base(uintmax_t nb, uint32_t base);
int					ft_add_spaces(int nb_spaces, int len, char c);

void				ft_detect_flags(const char *str, t_docker *data);
void				ft_detect_width(const char *str, t_docker *data, int who);
int					distrib_putbase(t_docker *data, uintmax_t result, int base, uint8_t flag);

int					ftp_putbase(uintmax_t n, uint32_t base, uint8_t flag,
								t_docker *data);
int					ftp_octal(uint32_t nb, va_list args, t_docker *data);
int					ftp_putchar(uint32_t c);
int					ftp_putstr(uint8_t *str);
int					ftp_strlen(uint8_t *str);
int					ftp_putnbr(int64_t n, t_docker *data);
int					ftp_putnbr_long(int64_t n, t_docker *data);

int					call_putstr(const char *str, va_list args, t_docker *data);
int					call_putchar(const char *str, va_list args, t_docker *data);
int					call_putnbr(const char *str, va_list args, t_docker *data);
int					call_putbase(const char *str, va_list args, t_docker *data);
int					call_putbase_long(const char *str, va_list args, t_docker *data);
int					call_putnbr_long(const char *str, va_list args, t_docker *data);
int					call_putwchar(const char *str, va_list args, t_docker *data);
int					call_putwstr(const char *str, va_list args, t_docker *data);
int					call_putadress(const char *str, va_list args, t_docker *data);
int					call_purcent(const char *str, va_list args, t_docker *data);

t_docker			*init_tabptr(void);
void				detect_conversion(const char *str, t_docker *data);
uintmax_t			unsigned_conversion(t_docker *data, va_list args);
intmax_t			signed_conversion(t_docker *data, va_list args);
int					ft_check_valid(const char *str, t_docker *data);
#endif
