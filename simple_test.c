/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:57:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/24 18:58:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <locale.h>
#ifndef FMT
# define FMT "\n%#.0o"
#endif
#ifndef ARG_LIST
# define ARG_LIST 0
#endif

int	main(int argc, char **argv)
{
	int test;

	//setlocale(LC_ALL, "");
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
	return (0);
}
