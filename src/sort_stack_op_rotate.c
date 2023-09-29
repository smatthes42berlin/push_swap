/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_op_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 17:53:08 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_a_b *stack_a_b)
{
	stack_a_b->a = stack_a_b->a->prev;
	ft_printf("ra\n");
}

void	rotate_b(t_stack_a_b *stack_a_b)
{
	stack_a_b->b = stack_a_b->b->prev;
	ft_printf("rb\n");
}

void	rev_rotate_a(t_stack_a_b *stack_a_b)
{
	stack_a_b->a = stack_a_b->a->next;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_stack_a_b *stack_a_b)
{
	stack_a_b->b = stack_a_b->b->next;
	ft_printf("rrb\n");
}
