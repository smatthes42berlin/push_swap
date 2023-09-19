/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/19 10:16:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

t_list_dc	*dc_lst_swap(t_list_dc **lst)
{
	t_list_dc	*head;
	t_list_dc	*second;

	head = *lst;
	if (!lst || !head)
		return (NULL);
	if (dc_lst_exactly_one(head))
		return (head);
	else
	{
		second = head->next;
		head->next = second->next;
		second->prev = head->prev;
		second->next->prev = head;
		head->prev->next = second;
		head->prev = second;
		second->next = head;
		*lst = second;
	}
	return (second);
}
