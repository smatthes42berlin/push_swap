/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 18:47:32 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a_b	*sort_stack_5(t_stack_a_b *stack_a_b)
{
	int	num;

	num = stack_a_b->length_a;
	// watch out for stack size of 4 or 5
	push_smallest_2_to_b(stack_a_b);
	sort_stack_3(stack_a_b);
	push_a(stack_a_b);
	push_a(stack_a_b);
	return (stack_a_b);
}

t_stack_a_b	*push_smallest_2_to_b(t_stack_a_b *stack_a_b)
{
	int	max_val;

	max_val = stack_a_b->length_a;
	push_smallest(stack_a_b, max_val - 1);
	push_next_smallest(stack_a_b, max_val - 2);
}

int	get_index(t_stack_a_b *stack_a_b, int val)
{
	int			index;
	int			next_val;
	t_list_dc	*temp;

	index = 0;
	temp = stack_a_b->a;
	next_val = *(int *)stack_a_b->a->content;
	while (next_val != val)
	{
		index++;
		temp = temp->next;
		next_val = *(int *)temp->content;
	}
	return (index);
}

void	push_smallest(t_stack_a_b *stack_a_b, int smallest_val)
{
	int	smallest_index;

	smallest_index = get_index(stack_a_b, smallest_val);
	if (smallest_index <= 2)
	{
		rev_rotate_push(stack_a_b, smallest_val, smallest_index);
	}
	else
	{
		rotate_push(stack_a_b, smallest_val, smallest_index);
	}
}
