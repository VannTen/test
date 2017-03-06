/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:27:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/06 14:12:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "display.h"
#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

void	test_format_string_prod(const char *fmt, ...);

static char	*produce_long_fmt(size_t conv_number)
{
	char	*fmt;
	char	conv[] = "%w";
	size_t	count;

	count = 0;
	fmt = malloc( conv_number * sizeof(char) * (sizeof(conv) -1) + 1);
	while (count < conv_number)
	{
		ft_strcpy(fmt + (count * (sizeof(conv) - 1)), conv);
		count++;
	}
	fmt[(count - 1) * (sizeof(conv) - 1)] = '\0';
	printf("long fmt is : %s\n", fmt);
	return (fmt);
}

int main(int argc, char **argv)
{
	char *fmt;
	char *fmt_2;
	char *long_fmt;

	if (argc != 2)
			fmt = "%1$*1$.*1$d";
	else
			fmt = argv[1];
	if (!(argc < 3))
		fmt_2 = argv[2];
	else
		fmt_2 = "%w %w";
	if (!(argc < 4))
		long_fmt = argv[3];
	else
		long_fmt = produce_long_fmt(50000);
	printf("1 %s\n2 %s\n",fmt, fmt_2);
//	test_format_string_prod(fmt, 32, 25, 52);
//	test_format_string_prod(fmt_2);
	test_format_string_prod(long_fmt);
	free(long_fmt);
	return (0);
}

void	test_format_string_prod(const char *fmt, ...)
{
	va_list ap;
	t_format_string *parsed;

	va_start(ap, fmt);
	parsed = ft_full_fmt(fmt, &ap);
	va_end(ap);
	display_format_string_conv(parsed);
	printf("%zu\n", ft_get_resulting_length(parsed));
	fmt_destroy(parsed);
}

