/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:44:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/05 12:36:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);
int main(void)
{
	char *line;
	printf("%d\n" ,get_next_line(STDIN_FILENO, NULL));
	printf("%d\n", get_next_line(-1, &line));
	printf("%d\n", get_next_line(-45, &line));
	return (0);
}
