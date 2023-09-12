/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_lst_print_whole_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 18:12:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

void	dc_lst_print_whole_str(t_list_dc *lst_ptr)
{
	t_list_dc	*head;

	head = lst_ptr;
	if (!lst_ptr)
		return ;
	dc_lst_print_one_str(lst_ptr);
	while (head != lst_ptr->next)
	{
		lst_ptr = lst_ptr->next;
		dc_lst_print_one_str(lst_ptr);
	}
	ft_printf(CYAN);
	ft_printf("---ALL PRINTED---\n");
	ft_printf(WHITE);
	return ;
}
