/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_op_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 17:28:23 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack_a_b *stack_a_b)
{
	t_list_dc	*temp;

	temp = dc_lst_pop(&(stack_a_b->a));
	dc_lst_add_front(&(stack_a_b->b), temp);
	if (temp)
	{
		(stack_a_b->length_b)++;
		(stack_a_b->length_a)--;
	}
	ft_printf("pb\n");
}

void	push_a(t_stack_a_b *stack_a_b)
{
	t_list_dc	*temp;

	temp = dc_lst_pop(&(stack_a_b->b));
	dc_lst_add_front(&(stack_a_b->a), temp);
	if (temp)
	{
		(stack_a_b->length_b)--;
		(stack_a_b->length_a)++;
	}
	ft_printf("pa\n");
}
