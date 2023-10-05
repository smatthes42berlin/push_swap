/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/05 11:54:06 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a_b	*sort_stack_main(t_stack_a_b *stack_a_b)
{
	if (stack_a_b->length_a == 2)
		return (sort_stack_2(stack_a_b));
	if (stack_a_b->length_a == 3)
		return (sort_stack_3(stack_a_b, 0));
	if (stack_a_b->length_a <= 5)
		return (sort_stack_5(stack_a_b));
	return (sort_big_5(stack_a_b));
}
