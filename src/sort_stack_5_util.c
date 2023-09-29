/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_5_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 18:45:12 by smatthes         ###   ########.fr       */
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

void	rev_rotate_push(t_stack_a_b *stack_a_b, int val)
{
	int	cur_val;

	cur_val = *(int *)stack_a_b->a->content;
	while (cur_val )
	{
	}
}
