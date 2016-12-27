/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/27 16:29:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "fillit.h"
#include "libft.h"
#include <unistd.h>

void	ft_display_char_lst(t_lst *elem)
{
	ft_putendl((char*)elem->content);
}

void	ft_display_point(t_rel_position *point)
{
	ft_putstr("x: ");
	ft_putnbr(point->x);
	ft_putchar(',');
	ft_putstr("y: ");
	ft_putnbr(point->y);
}

void	ft_display_piece_coord(t_rel_position *piece)
{
	size_t	index;
	index = 0;

	while (index < 3)
	{
		ft_display_point(piece + index);
		ft_putchar('\n');
		index++;
	}
}

void	ft_display_tetri(t_tetrimino *tetri)
{
		ft_putstr("Tetrimino ");
		ft_putchar(tetri->identifier);
		ft_putchar('\n');
		ft_display_piece_coord(tetri->relative_coordinates);
		ft_putchar('\n');
		ft_putstr("Offset : ");
		ft_display_point(tetri->offset);
		ft_putchar('\n');
}

void	ft_display(t_lst *piece)
{
	ft_putendl("start of piece");
	ft_display_tetri((t_tetrimino*)piece->content);
}


int	main(int argc, char **argv)
{
	t_lst	*tetris_lst;

	if (argc != 2)
		return (1);
	tetris_lst = ft_parser(argv[1]);
	if (tetris_lst == NULL)
		return (1);
	f_lstiter(tetris_lst, &ft_display);
	return (0);
}
