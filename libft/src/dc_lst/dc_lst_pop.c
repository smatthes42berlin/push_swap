/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/18 16:06:58 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

t_list_dc	*dc_lst_pop(t_list_dc **lst)
{
	t_list_dc	*old_head;
	t_list_dc	*new_head;

	if (!lst || !*lst)
		return (NULL);
	old_head = *lst;
	if (dc_lst_exactly_one(*lst))
		*lst = NULL;
	else
	{
		// set next prev
	}
	return (old_head);
}
