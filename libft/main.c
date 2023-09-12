/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:35:25 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 18:30:57 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

int	main(void)
{
	char		*test;
	t_list_dc	*lst;
	t_list_dc	*new;
	int			i;
	int			size;
	char		*str;

	i = 1;
	test = "0";
	lst = NULL;
	size = dc_lst_size(lst);
	ft_printf("size is %d\n", size);
	lst = dc_lst_new(test);
	size = dc_lst_size(lst);
	ft_printf("size is %d\n", size);
	while (i < 4)
	{
		str = ft_itoa(i);
		new = dc_lst_new(str);
		dc_lst_add_front(&lst, new);
		i++;
	}
	dc_lst_print_whole_str(lst);
	size = dc_lst_size(lst);
	ft_printf("size is %d\n", size);
	return (1);
}
