/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 14:15:39 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/05 14:19:12 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define MASK_1 "0xxxxxxx"
#define MASK_2 "110xxxxx 10xxxxxx"
#define MASK_3 "1110xxxx 10xxxxxx 10xxxxxx"
#define MASK_4 "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"

int			ftp_putwchar(wchar_t c)
{

}
