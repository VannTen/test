/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:57:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/23 14:35:16 by mgautier         ###   ########.fr       */
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
# define FMT "\neeee%drer%derere"
#endif
#ifndef ARG_LIST
# define ARG_LIST 45, 42, L'Ÿ', 45
#endif

int	main(int argc, char **argv)
{
	int test;

	//setlocale(LC_ALL, "");
	if (argc == 2 && ft_strcmp(argv[1], "true") == 0)
			test = printf(FMT, ARG_LIST);
	else
		test = ft_printf(FMT, ARG_LIST);
	printf("\nReturn value : %d\n", test);
	return (0);
}
