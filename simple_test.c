/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:57:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 18:31:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#define FMT "TRE : %ls\n"
#define ARG_LIST L"한국어q日本語"
int	main(void)
{
	int test;
	int control;
	setlocale(LC_ALL, "en_US.UTF-8");
	test = ft_printf(FMT, ARG_LIST);
	control = printf(FMT, ARG_LIST);
	printf("\nReturn = %d\nControl = %d\n", test, control);
	return (0);
}
