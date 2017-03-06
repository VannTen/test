/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/06 18:29:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "variadic_args_defs.h"
#include "conv_len_interface.h"
#include "test_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

int		ft_printf(const char *format_string, ...);
void	display_conversion(void *_conversion);
void	display_format_string_conv(const char *format_string);
#define VAR(X, Y) fomt->arg_list[X].parameter.Y
int	main(int argc, char **argv)
{
	int		test;
	char	*fmt;
	char	*atom;
	int		repeat;

	if (argc < 2)
		atom = "Vaine est la farce\n";
	else
		atom = argv[1];
	if (argc < 3)
		repeat = 50000;
	else
		repeat = ft_atoi(argv[2]);
	fmt = produce_long_fmt(atom, repeat);
	test = ft_printf(fmt , 50, 58);
	printf("test : %d\n", test);
	return (0);
}

/*
void	test_printf(const char *fmt, ...)
{
	va_list ap;
	t_format_string *fomt;

	fomt = ft_format_string_parser(fmt);
	f_lstiter_content(fomt->conversion_list->begin_lst, &display_conversion);
	va_start(ap, fmt);
	fomt->arg_list = ft_get_var_args(fomt->conversion_list, &ap);
	va_end(ap);
	printf("Mine\n");
	ft_putendl(VAR(1, t_ptr_char));
	printf(fmt, VAR(0, t_int), VAR(1, t_ptr_char), VAR(2, t_int));
	va_start(ap, fmt);
	printf("True printf\n");
	vprintf(fmt, ap);
	va_end(ap);
}
*/
