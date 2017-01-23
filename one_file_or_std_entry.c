/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_file_or_std_entry.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:49:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/23 16:12:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		gnl_return;
	if (argc == 1)
		fd = STDIN_FILENO;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
