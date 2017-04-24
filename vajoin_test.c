/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vajoin_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:10:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/24 12:11:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	char	*str;

	str = ft_strvajoin(4, "Doudou", "dada", "desds", "plouf");
	ft_putendl(str);
	return (0);
}

