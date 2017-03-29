/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:36:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 12:22:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_interface.h"
#include "libft.h"
#include <stdlib.h>

int	nbr_comp(void *number, void *number2)
{
	return (*(int*)number - *(int*)number2);
}

void	nbr_put(void *number)
{
	ft_putnbr(*(int*)number);
	ft_putchar('\n');
}

int main(void)
{
	int	tab[100];
	int index;
	t_btree *tree;

	index = 0;
	tree = btree_create(&nbr_comp);
	while (index < 100)
	{
		tab[index] = rand();
		btree_add(tree, tab + index);
		index ++;
	}
	btree_iter_in_order(tree, &nbr_put);
	return (0);
}
