/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_5_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/30 19:13:49 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_push(t_stack_a_b *stack_a_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		rotate_a(stack_a_b);
		i++;
	}
	push_b(stack_a_b);
}

void	rev_rotate_push(t_stack_a_b *stack_a_b, int index)
{
	int	i;

	i = 0;
	while (i < (stack_a_b->length_a - index))
	{
		rev_rotate_a(stack_a_b);
		i++;
	}
	push_b(stack_a_b);
}
