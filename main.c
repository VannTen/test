/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/31 17:47:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "ft_conversion_specifier.h"
#include "ft_types.h"
#include <stdlib.h>

void	display_conversion(t_conversion *conversion)
{
	size_t index_flags;

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
	t_format_string	format;
	t_conversion	*conversion;

	index = 0;
	printf("Type_nbr : %d\n", UNKNOWN_CONVERSION);
	while (index <= UNKNOWN_CONVERSION)
	{
		printf("type is : %c\n", g_types[index]);
		index++;
	}
	printf("Check arg test : %s \n", argv[1]);
	(void)argc;
	index = 0;
	format.arg_count = 0;
	format.conversion_list = f_fifo_create();
	format.string = argv[1];
	index = parser(format.string, index, &format);
	conversion = f_fifo_take(format.conversion_list);
	display_conversion(conversion);

}
