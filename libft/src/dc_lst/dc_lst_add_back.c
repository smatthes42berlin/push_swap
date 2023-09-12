/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 18:07:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

void	dc_lst_add_back(t_list_dc **lst, t_list_dc *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
}
