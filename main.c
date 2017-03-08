/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/08 13:47:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "variadic_args_defs.h"
#include "conv_len_interface.h"
#include "printf.h"
#include "test_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

void	display_conversion(void *_conversion);
void	display_format_string_conv(const char *format_string);
#define VAR(X, Y) fomt->arg_list[X].parameter.Y

int	test_printf(const char *fmt, t_bool is_true, ...)
{
	va_list ap;
	int		ret;

	va_start(ap, is_true);
	if (is_true)
		ret = vprintf(fmt, ap);
	else
		ret = ft_vdprintf(STDOUT_FILENO, fmt, &ap);
	va_end(ap);
	return (ret);
}

int	main(int argc, char **argv)
{
	int		test;
	char	*fmt;
	char	*atom;
	int		repeat;
	t_bool	is_true;

	if (argc < 2)
		atom = "Vaine est la farce\n";
	else
		atom = argv[1];
	if (argc < 3)
		repeat = 50000;
	else
		repeat = ft_atoi(argv[2]);
	if (argc < 4)
		is_true = FALSE;
	else
		is_true = ft_strncmp(argv[3], "true", 4) == 0 ? TRUE : FALSE;
	fmt = produce_long_fmt(atom, repeat);
	test = test_printf(fmt, is_true, 50, 58);
	printf("\ntest : %d\n", test);
	free(fmt);
	if (is_true)
		printf("True printf\n");
	else
		printf("My printf\n");
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
