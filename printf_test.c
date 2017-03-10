/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:19:20 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 17:52:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
	int index;
	setlocale(LC_ALL, "");
	//	printf("|%1$*2$d| |%1$*1$d| |%1$*3$d|", 3, 8,960);
	//	printf("%wd %w");
	if (malloc(0) == NULL)
	{
		index = printf("%d", 56);
		printf("return is %d\n", index);
	}
	return (0);
}


/*
** order for integer;
**
** determine arg len(flags ');
** determine precision
** determine flags(+ #)
** determine field_widht
**
** order for strings;
**
** determine arg len(precision);
** determine field_widht
**
** order for floats;
**
** determine arg len(flags ');
** determine precision
** determine flags(+ #)
** determine field_widht
*/
