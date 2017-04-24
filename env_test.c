/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 20:01:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/24 20:13:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_interface.h"

extern char **environ;

int	main(int argc, char **argv)
{
	char		**env;
	const char	*key;
	const char	*value;
	int	index;

	env = ft_string_array_dup(environ);
	index = 1;
	while (index < argc)
	{
		key = get_key(argv[index]);
		value = get_value(argv[index]);
		env = ft_putenv(key, value, env);
		ft_strdel(&key);
		index++;
	}
	ft_print_string_array(env, '\n');
	return (0);
}
