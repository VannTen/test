/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/23 15:01:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_reader.h"
#include "libft.h"
#include "fillit.h"

t_rel_position	*ft_string_to_coordinates(char *str);
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

t_lst	*ft_transform(t_lst *piece)
{
	t_lst *new_link;

	new_link = f_lstnew(NULL);
	if (new_link != NULL)
		new_link->content = ft_string_to_coordinates((char*)piece->content);
	return (new_link);
}

void	ft_display(t_lst *piece)
{
	ft_putendl("start of piece");
	ft_display_piece_coord((t_rel_position*)piece->content);
}


int	main(int argc, char **argv)
{
	int	fd;
	t_fifo *piece_lst;
	t_lst	*pieces;

	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (1);
	piece_lst = ft_file_reader(fd);
	if (piece_lst == NULL)
		return (1);
	printf("%p begin \n %p end \n", piece_lst->begin_lst, piece_lst->end_lst);
	f_lstiter(piece_lst->begin_lst, &ft_display_char_lst);
	if (f_lst_every_valid(piece_lst->begin_lst, &ft_valid_pieces_format) != NULL)
		return (1);
	close(fd);
	pieces = f_lstmap(piece_lst->begin_lst, &ft_transform);
	f_lstiter(pieces, &ft_display);
	return (0);
}
