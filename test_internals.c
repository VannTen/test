/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:27:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 19:09:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "display.h"
#include <stdarg.h>

void	test_format_string_prod(const char *fmt, ...);

int main(void)
{
	test_format_string_prod("%1$*1$.*1$d", 32, 25, 52);
}

void	test_format_string_prod(const char *fmt, ...)
{
	va_list ap;
	t_format_string *parsed;

	va_start(ap, fmt);
	parsed = ft_full_fmt(fmt, &ap);
	va_end(ap);
	display_format_string_conv(parsed);
}

