/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:13:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 18:55:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "format_string_defs.h"
#include "libft.h"
#include <stdio.h>

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
	printf("Conversion type is %c (%d)\n", g_conv_types[conversion->type], conversion->type);
}

void	display_format_string_conv(t_format_string *fmt)
{
	f_lstiter_content(fmt->conversion_list->begin_lst, &display_conversion);
}
