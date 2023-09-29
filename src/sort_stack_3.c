/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 17:50:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a_b	*sort_stack_3(t_stack_a_b *stack_a_b)
{
	if (*(int *)stack_a_b->a->content == 0)
	{
		rev_rotate_a(stack_a_b);
		swap_a(stack_a_b);
		rotate_a(stack_a_b);
	}
	else if (*(int *)stack_a_b->a->content == 1)
	{
		if (*(int *)stack_a_b->a->next->content == 2)
			rev_rotate_a(stack_a_b);
		else
			swap_a(stack_a_b);
	}
	else
	{
		if (*(int *)stack_a_b->a->next->content == 0)
			rev_rotate_a(stack_a_b);
		else
		{
			swap_a(stack_a_b);
			rotate_a(stack_a_b);
		}
	}
	return (stack_a_b);
}
