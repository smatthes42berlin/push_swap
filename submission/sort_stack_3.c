/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/30 19:15:32 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra_sa_rra(t_stack_a_b *stack_a_b);

t_stack_a_b	*sort_stack_3(t_stack_a_b *stack_a_b, int offset)
{
	if (*(int *)stack_a_b->a->content == (0 + offset))
	{
		if (*(int *)stack_a_b->a->next->content == (2 + offset))
			ra_sa_rra(stack_a_b);
	}
	else if (*(int *)stack_a_b->a->content == (1 + offset))
	{
		if (*(int *)stack_a_b->a->next->content == (2 + offset))
			rev_rotate_a(stack_a_b);
		else
			swap_a(stack_a_b);
	}
	else
	{
		if (*(int *)stack_a_b->a->next->content == (0 + offset))
			rotate_a(stack_a_b);
		else
		{
			swap_a(stack_a_b);
			rev_rotate_a(stack_a_b);
		}
	}
	return (stack_a_b);
}

static void	ra_sa_rra(t_stack_a_b *stack_a_b)
{
	rotate_a(stack_a_b);
	swap_a(stack_a_b);
	rev_rotate_a(stack_a_b);
}
