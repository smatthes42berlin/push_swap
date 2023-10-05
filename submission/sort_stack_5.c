/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/30 19:14:02 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a_b	*sort_stack_5(t_stack_a_b *stack_a_b)
{
	int	num;

	num = stack_a_b->length_a;
	push_smallest_2_to_b(stack_a_b);
	if (num == 4)
		sort_stack_2(stack_a_b);
	else
		sort_stack_3(stack_a_b, 2);
	push_a(stack_a_b);
	push_a(stack_a_b);
	return (stack_a_b);
}

t_stack_a_b	*push_smallest_2_to_b(t_stack_a_b *stack_a_b)
{
	push_value_b(stack_a_b, 0);
	push_value_b(stack_a_b, 1);
	return (stack_a_b);
}

void	push_value_b(t_stack_a_b *stack_a_b, int val)
{
	int	index;

	index = get_index(stack_a_b, val);
	if (index <= 2)
		rotate_push(stack_a_b, index);
	else
		rev_rotate_push(stack_a_b, index);
}
