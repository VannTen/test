/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:57:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/13 19:34:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <limits.h>
#define FMT "TRE : %1$lld TRE : %2$*3$djoooooooo\n"
#define ARG_LIST LLONG_MAX, 3290, -9
int	main(void)
{
	int test;
	int control;
	test = ft_printf(FMT, ARG_LIST);
	control = printf(FMT, ARG_LIST);
	printf("\nReturn = %d\nControl = %d\n", test, control);
	return (0);
}
