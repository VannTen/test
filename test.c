/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:51:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/07 17:05:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
	size_t	size;

	size = INT_MAX;
	size++;
	printf("%zu\n%d\n", size, INT_MIN);
	return (0);
}
