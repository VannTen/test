/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:44:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/05 15:03:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);
int main(int argc, char **argv)
{
	char *line;
	int	fd;
	int count;

	count = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			while (get_next_line(fd, &line) != 0)
			{
				count++;
				printf("%s\n", line);
				free(line);
			}
		printf("%d\n", count);
		printf("Return = %d\n", get_next_line(fd, &line));
		}
	}
	return (0);
}
