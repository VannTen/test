/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:57:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 13:49:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define FMT "%d\n"
#define ARG_LIST 78
int	main(void)
{
	ft_printf(FMT, ARG_LIST);
	return (0);
}
