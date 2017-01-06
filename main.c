/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:29:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/04 18:41:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	get_next_line(const int fd, char **line);

int	main(int argc, char **argv)
{
	int		*file_to_read;
	int		arg_count;
	char	*line;
	t_bool	files_left;
	t_bool	file_not_over;

	file_to_read = (int*)malloc(sizeof(int) * (argc - 1));
	if (argc == 1)
		file_to_read[0] = STDIN_FILENO;
	else
	{
		arg_count = 0;
		while (arg_count + 1 < argc)
		{
			file_to_read[arg_count] = open(argv[arg_count + 1], O_RDONLY);
			arg_count++;
		}
	}
	files_left = TRUE;
	while (files_left)
	{
		files_left = FALSE;
		arg_count = 0;
		while (arg_count + 1 < argc)
		{
			file_not_over = get_next_line(file_to_read[arg_count], &line) == 1;
			files_left = file_not_over || files_left;
			if (file_not_over)
				ft_putendl(line);
			ft_strdel(&line);
			arg_count++;
		}
	}
	return (0);
}
