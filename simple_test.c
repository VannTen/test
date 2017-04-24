/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:57:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/08 13:59:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <locale.h>
#ifndef FMT
# define FMT "%d %d"
#endif
#ifndef ARG_LIST
# define ARG_LIST 5, 1
#endif

int	main(int argc, char **argv)
{
	int test;

	if (argc >= 3 && ft_strcmp(argv[2], "locale") == 0)
		setlocale(LC_ALL, "");
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
	printf("MB_CUR_MAX : %d\n", MB_CUR_MAX);
	return (0);
}
