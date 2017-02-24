/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:51:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 18:03:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
int test(int arg, ...)
{
	va_list ap;
	va_list	ap_2;
	va_list	*ad;
	va_list	*ac;
	va_start(ap, arg);
	va_copy(ap_2, ap);
	ac = &ap_2;
	ad = &ap;
	printf("%d\n", va_arg(ap, int));
	if (ac != ad)
		printf("diff\n");
	else
		printf("same\n");
	return (0);
}

int main(void)
{
	test(2, 3, 4);
	return (0);
}
