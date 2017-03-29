/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:02:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 16:18:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "wide_char_interface.h"

int main(void)
{
	char buf[1000] = {0};
	int ret;

	setlocale(LC_ALL, "");
	ret = ft_wcstrtomb(buf, L"한국어q日本語");
	write(STDOUT_FILENO, buf, ret);
	return (0);
}
