/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/30 17:48:16 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a_b	*sort_stack_2(t_stack_a_b *stack_a_b)
{
	int	first;
	int	second;

	first = *(int *)stack_a_b->a->content;
	second = *(int *)stack_a_b->a->next->content;
	if (first > second)
		swap_a(stack_a_b);
	return (stack_a_b);
}
