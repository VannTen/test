/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 12:11:53 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/26 12:17:47 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#define BUF_SIZE 20

int		main(int argc, char **argv)
{
	int fd;
	int i;
	char buf[BUF_SIZE + 1];

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((i = read(fd, buf, BUF_SIZE)))
	{
		buf[i] = '\0';
		printf("%s", buf);
	}
	ft_check_piece(buf);
	return (0);
}
