/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:01:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/02 14:14:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_integer.h"
#include "libft.h"
#include <limits.h>

char	*ft_itoa_base(t_integer value, int base, t_bool maj, t_bool is_signed);

int		main(void)
{
	t_integer	number;
	char		*str;

	number.negative = INTMAX_MAX;
	str = ft_itoa_base(number, 16, TRUE, TRUE);
	ft_putendl(str);
	ft_strdel(&str);

	number.positive = UINTMAX_MAX;
	str = ft_itoa_base(number, 16, TRUE, FALSE);
	ft_putendl(str);
	ft_strdel(&str);
	return (0);
}
