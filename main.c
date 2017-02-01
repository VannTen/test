/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/01 12:09:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "ft_conversion_specifier.h"
#include "ft_types.h"
#include <stdlib.h>

void	display_conversion(void *_conversion)
{
	size_t index_flags;
	t_conversion *conversion;

	conversion = _conversion;
	index_flags = 0;
	printf("Required argument is index %d\n", conversion->arg_index);
	while (index_flags < FLAGS_NBR)
	{
		printf("Flags %c is set to %d\n", g_flags[index_flags],
				conversion->flags[index_flags]);
		index_flags++;
	}
	printf("Field width is %d and is an arg : %d\n", conversion->field_width.value, conversion->field_width.is_arg);
	printf("Precision is %d and is an arg : %d\n", conversion->precision.value, conversion->precision.is_arg);
	printf("Lenght modifier is %c (%d)\n", g_length_modifier[conversion->length_modifier], conversion->length_modifier);
	printf("Conversion type is %c (%d)\n", g_types[conversion->type], conversion->type);
}

int	main(int argc, char **argv)
{
	size_t	index;
	t_format_string	*conv_list;

	if (argc != 2)
		return (1);
	index = 0;
	printf("Check arg test : %s \n", argv[1]);
	conv_list = ft_format_string_parser(argv[1]);
	f_lstiter_content (conv_list->conversion_list->begin_lst, &display_conversion);
	return (0);
}
