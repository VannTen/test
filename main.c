/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/04 12:54:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
int	get_next_line(const int fd, char **line);

int	main(int argc, char **argv)
{
	int	file_to_read;
	char	*line;

	if (argc == 1)
		file_to_read = STDIN_FILENO;
	else
		file_to_read = open(argv[1], O_RDONLY);
	while (get_next_line(file_to_read, &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
