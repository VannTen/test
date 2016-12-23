/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/23 11:48:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_reader.h"
#include "libft.h"

void	ft_display_char_lst(t_lst *elem)
{
	ft_putendl((char*)elem->content);
}

int	main(int argc, char **argv)
{
	int	fd;
	t_fifo *piece_lst;

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
	return (0);
}
