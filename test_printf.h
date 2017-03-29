/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:39:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/06 17:45:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H
# include <stddef.h>

char	*produce_long_fmt(char *text, size_t reapeat);
void	test_format_string_prod(const char *fmt, ...);

#endif
