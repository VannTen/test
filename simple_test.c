/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:57:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 19:04:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <locale.h>
#ifndef MY_LOCALE
# define MY_LOCALE ""
#endif
#ifndef FMT
# define FMT "%5.10o"
#endif
#ifndef ARG_LIST
# define ARG_LIST 15
#endif

int	main(int argc, char **argv)
{
	int test;

//	ft_putstr(MY_LOCALE);
	setlocale(LC_ALL, MY_LOCALE);
	if (argc == 2 && ft_strcmp(argv[1], "true") == 0)
			test = printf(FMT, ARG_LIST);
	else if (argc == 2 && ft_strcmp(argv[1], "leaks") == 0)
	{
		test = ft_printf(FMT, ARG_LIST);
		while (1);
	}
	else
		test = ft_printf(FMT, ARG_LIST);
	printf("\nReturn value : %d\n", test);
	printf("MB_CUR_MAX : %d\nLocale : %s\n", MB_CUR_MAX, MY_LOCALE);
	return (0);
}
