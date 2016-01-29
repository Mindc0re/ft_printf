/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ptrfct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 09:04:26 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/29 10:04:23 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		print_str(char *str, int i, char c)
{
	i = 42;
	c = 'U';
	printf("%s\n", str);
	return (0);
}

int		print_nb(char *str, int i, char c)
{
	str = "BWEH";
	c = 'L';
	printf("%d\n", i);
	return (0);
}

int		print_char(char *str, int i, char c)
{
	i = 42;
	str = "BWAH";
	printf("%c\n", c);
	return (0);
}

int		main(void)
{
	char	*str = "Dieuson est encore en retard";
	int		i = 25;
	char	c = 'K';
	int		(*ptr_fct[128])(char *, int, char);

	ptr_fct['s'] = &print_str;
	ptr_fct['d'] = &print_nb;
	ptr_fct['c'] = &print_char;

	(*ptr_fct['s'])(str, i, c);
	(*ptr_fct['d'])(str, i, c);
	(*ptr_fct['c'])(str, i, c);
	return (0);
}
