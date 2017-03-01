/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:51:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 17:05:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *str;
	char a;
	size_t	size;

	a = 'a';
	size = 8;
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		write(STDOUT_FILENO, &a, 1);
	else
		printf("Worsk");
	return (0);
}
