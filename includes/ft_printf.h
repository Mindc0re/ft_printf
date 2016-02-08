/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:23:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/08 17:45:12 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# include "../libftprintf/libftprintf.h"

typedef struct		s_docker
{
	int				i;
	int				len;
	int				(*fct[256])(char *, va_list, struct s_docker *);
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

	enum {
					h,
					hh,
					l,
					ll,
					j,
					z
	}				length;
}					t_docker;

char				*ft_detect_length(char *str, t_docker *data);
char				*ft_detect_flags(char *str, t_docker *data);
char				*ft_detect_width(char *str, t_docker *data, int who);
int					ft_printf(char *str, ...);

int					ftp_flag_hh(char *str, t_docker *data, va_list pointeur);
int					ftp_flag_hh_i(char c, t_docker *data);
int					ftp_flag_hh_o(unsigned char u, t_docker *data);
int					ftp_flag_hh_u(unsigned char u, t_docker *data);
int					ftp_flag_x(unsigned char u, t_docker *data, char letter);

int					ftp_putbase(uint32_t n, uint32_t base, uint8_t flag, uint32_t dieze);
int					ftp_putchar(uint32_t c);
int					ftp_putstr(uint8_t *str);
int					ftp_strlen(uint8_t *str);
int					ftp_putnbr(int32_t n, uint32_t space, uint32_t more);

int					call_putstr(char *str, va_list args, t_docker *data);
int					call_putchar(char *str, va_list args, t_docker *data);
int					call_putnbr(char *str, va_list args, t_docker *data);
int					call_putbase(char *str, va_list args, t_docker *data);
int					call_putbase_long(char *str, va_list args, t_docker *data);
int					call_putnbr_long(char *str, va_list args, t_docker *data);
int					call_putwchar(char *str, va_list args, t_docker *data);
int					call_putwstr(char *str, va_list args, t_docker *data);
void				init_tabptr(t_docker *data);

#endif
