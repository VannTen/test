/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:02:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/17 19:02:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

int	ft_wctomb(char *dst, wchar_t wchar);
int main(void)
{
	char buf[10] = {0};
	int ret;

	setlocale(LC_ALL, "");
	ret = 0;
	ret = ft_wctomb(buf,0201510);
	buf[ret + 1] = '\0';
	write(STDOUT_FILENO, buf, ret);
	return (0);
}
