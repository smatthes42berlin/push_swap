/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:35:25 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/18 13:50:12 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

void	*add_one_thousand(void *num)
{
	int	num_to_i;

	num_to_i = ft_atoi((char *)num);
	num_to_i += 1000;
	return (ft_itoa(num_to_i));
}

int	main(void)
{
	char		*test;
	t_list_dc	*lst;
	t_list_dc	*new;
	t_list_dc	*mapped;
	int			i;
	int			size;

	i = 1;
	test = ft_strdup("0");
	lst = NULL;
	size = dc_lst_size(lst);
	ft_printf("size is %d\n", size);
	lst = dc_lst_new(test);
	size = dc_lst_size(lst);
	ft_printf("size is %d\n", size);
	while (i < 4)
	{
		test = ft_itoa(i);
		new = dc_lst_new(test);
		dc_lst_add_front(&lst, new);
		i++;
	}
	size = dc_lst_size(lst);
	ft_printf("size is %d\n", size);
	// mapped = dc_lst_map(lst, &add_one_thousand, &free);
	ft_printf("%p\n", lst);
	dc_lst_print_whole_str(lst);
	// dc_lst_print_whole_str(mapped);
	// dc_lst_clear(&lst, &free);
	// dc_lst_print_whole_str(lst);
	return (1);
}
