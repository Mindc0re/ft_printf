/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:31:07 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/19 15:33:23 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		void_truc()
{
	return (0);
}

int		main(void)
{
	int ret_ft = 0;
	int ret = 0;
	int i;
	unsigned long l;
	char *str;

	/* ************ LEGIT SPACE TESTS ************** */
	ft_putstr("-------------- Tests flag espace ---------------\n\n");
	ret_ft += ft_printf("% d\n", 9999);
	ret += printf("% d\n", 9999);

	ret_ft += ft_printf("% d\n", -9999);
	ret += printf("% d\n", -9999);

	ret_ft += ft_printf("% i\n", 9999);
	ret += printf("% i\n", 9999);

	ret_ft += ft_printf("% i\n", -9999);
	ret += printf("% i\n", -9999);

	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/* ************** NO CONV TESTS **************** */
	ft_putstr("-------------- Tests pas de conversion ---------------\n\n");
	ret_ft = ft_printf("Ceci est un test\n");
	ret = printf("Ceci est un test\n");
	ret_ft += ft_printf("Ceci est un\ndouble test\n");
	ret += printf("Ceci est un\ndouble test\n");
	ret_ft += ft_printf("");
	ret += printf("");
	ret_ft += ft_printf("\n");
	ret += printf("\n");
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/*************** Simple s conversions ************ */
	ft_putstr("-------------- Tests s conversion ---------------\n\n");
	ret_ft = ft_printf("%s", "abc\n");
	ret = printf("%s", "abc\n");
	ret_ft += ft_printf("111%s333", "222\n");
	ret += printf("111%s333", "222\n");
	ret_ft += ft_printf("%s333", "222\n");
	ret += printf("%s333", "222\n");
	ret_ft += ft_printf("111%s", "222\n");
	ret += printf("111%s", "222\n");
	ret_ft += ft_printf("{%s}\n", "");
	ret += ft_printf("{%s}\n", "");
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/*************** Simple d conversions *********** */
	ft_putstr("-------------- Tests d conversion ---------------\n\n");
	ret_ft = ft_printf("%d\n", 42);
	ret = printf("%d\n", 42);
	ret_ft += ft_printf("%d\n", -42);
	ret += printf("%d\n", -42);
	ret_ft += ft_printf("before %d after\n", 42);
	ret += printf("before %d after\n", 42);
	ret_ft += ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	ret += printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	ret_ft += ft_printf("a%db%dc%dd\n", 1, -2, 3);
	ret += ft_printf("a%db%dc%dd\n", 1, -2, 3);
	ret_ft += ft_printf("%d\n", INT_MAX);
	ret += printf("%d\n", INT_MAX);
	ret_ft += ft_printf("%d\n", INT_MIN);
	ret += ft_printf("%d\n", INT_MIN);
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/******************* p conversions ************** */
	ft_putstr("-------------- Tests p conversion ---------------\n\n");
	ret_ft = ft_printf("%p\n", &i);
	ret = printf("%p\n", &i);
	ret_ft += ft_printf("%p\n", &l);
	ret += printf("%p\n", &l);
	ret_ft += ft_printf("%p\n", &str);
	ret += printf("%p\n", &str);
	ret_ft += ft_printf("%p\n", &strlen);
	ret += printf("%p\n", &strlen);
	ret_ft += ft_printf("%p\n", 0);
	ret += ft_printf("%p\n", 0);
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/******************* % conversions ************** */
	ft_putstr("-------------- Tests % conversion ---------------\n\n");
	ret_ft = ft_printf("%%\n");
	ret = printf("%%\n");
	ret_ft += ft_printf("aa%%bb\n");
	ret += printf("aa%%bb\n");
	ret_ft = ft_printf("%%%%%%%%%%\n");
	ret = printf("%%%%%%%%%%\n");
	ret_ft += ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ret += printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ret_ft += ft_printf("{% %}\n");
	ret += printf("{% %}\n");
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/********************** MIX ********************** */
	ft_putstr("-------------- Tests mixed conversions ---------------\n\n");
	ret_ft = ft_printf("s: %s, p: %p, d:%d\n", "a string", &atoi, 42);
	ret = printf("s: %s, p: %p, d:%d\n", "a string", &atoi, 42);
	ret_ft += ft_printf("%s %p %d %d %p %s %p %p %s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	ret += printf("%s %p %d %d %p %s %p %p %s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/******************** S conversions ************** */
/*	ret_ft = ft_printf("%S\n", L"米");
	ret_ft += ft_printf("%S\n", L"我是一只猫。");
	ret_ft += ft_printf("a%Sb%sc%S\n", L"我", "42", L"猫");
	ret_ft = ft_printf("%S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S %S\n",
				L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
				L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""); */
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
	/***************** O conversions ******************** */
	ft_putstr("-------------- Tests U conversions ---------------\n\n");
	ret_ft = ft_printf("%lU\n", ULONG_MAX / 2);
	ret = printf("%lU\n", ULONG_MAX / 2);
	printf("\n\nPrintf retourne %d caracteres et ft_printf retourne %d caracteres\n\n", ret, ret_ft);
/*
  	ret_ft += ft_printf(
	ret += printf(
	ret_ft += ft_printf(
	ret += printf( */
	return (0);
}