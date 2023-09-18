/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_lst_print_whole_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/18 15:45:45 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

void	dc_lst_print_whole_str(t_list_dc *lst_ptr)
{
	t_list_dc	*head;

	head = lst_ptr;
	if (!lst_ptr)
	{
		ft_printf(CYAN);
		ft_printf("---PASSED EMPTY LIST - NOTHING TO PRINT---\n");
		ft_printf(WHITE);
		return ;
	}
	dc_lst_iter_node(head, &dc_lst_print_one_str);
	ft_printf(CYAN);
	ft_printf("---ALL PRINTED---\n");
	ft_printf(WHITE);
	return ;
}
