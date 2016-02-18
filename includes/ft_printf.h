/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:23:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 11:14:07 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# include "../libftprintf/libftprintf.h"

# define FT_INIT(type,name,value)		type name = value

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
int					ft_printf(const char *format, ...);

int					longueur_nb(int32_t nb);
int					ft_add_spaces(int nb_spaces, int len, char c);

void				ft_detect_flags(const char *str, t_docker *data);
void				ft_detect_width(const char *str, t_docker *data, int who);

int					ftp_putbase(uint32_t n, uint32_t base, uint8_t flag,
								uint32_t dieze);
int					ftp_octal(uint32_t nb, va_list args, t_docker *data);
int					ftp_putchar(uint32_t c);
int					ftp_putstr(uint8_t *str);
int					ftp_strlen(uint8_t *str);
int					ftp_putnbr(int32_t n, uint32_t space, uint32_t more,
								int precision);

int					call_putstr(const char *str, va_list args, t_docker *data);
int					call_putchar(const char *str, va_list args, t_docker *data);
int					call_putnbr(const char *str, va_list args, t_docker *data);
int					call_putbase(const char *str, va_list args, t_docker *data);
int					call_putbase_long(const char *str, va_list args, t_docker *data);
int					call_putnbr_long(const char *str, va_list args, t_docker *data);
int					call_putwchar(const char *str, va_list args, t_docker *data);
int					call_putwstr(const char *str, va_list args, t_docker *data);
t_docker			*init_tabptr(void);
void				detect_conversion(const char *str, t_docker *data);
uintmax_t			unsigned_conversion(uintmax_t val, t_docker *data);
intmax_t			signed_conversion(intmax_t val, t_docker *data);
int					ft_check_valid(const char *str, t_docker *data);
#endif
