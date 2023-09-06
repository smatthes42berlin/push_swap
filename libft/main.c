/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:35:25 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/03 08:20:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_test_main.h"

static int	fd_glob;

void	test(void)
{
	char	*gnl_res;

	gnl_res = get_next_line(fd_glob);
	while (gnl_res)
	{
		ft_printf("%s", gnl_res);
		gnl_res = get_next_line(fd_glob);
	}
}

int	main(void)
{
	char	*file_name;
	int		fd;

	file_name = "./srctest/get_next_line/test_files/manual_test_file.txt";
	fd = open(file_name, O_RDONLY);
	ft_printf("fd is %d\n\n", fd);
	if (fd == -1)
		return (1);
	fd_glob = fd;
	test();
	fd = close(fd);
	if (fd == -1)
		return (1);
	return (0);
}
