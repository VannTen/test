/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 12:11:53 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/27 15:01:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#define BUF_SIZE 20

unsigned int	ft_check_count(const char *piece);
int		main(int argc, char **argv)
{
	int fd;
	int i;
	char	*piece;

	i = 0;
	if (argc == 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	piece = ft_piece_reader(fd);
	printf("%s\n%u\n", piece, ft_check_count(piece));
	return (0);
}
