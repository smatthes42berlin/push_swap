/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_stacks_init_sort_param.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:30:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:50 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initilise_sorting_params(t_stack_a_b *stack_a_b)
{
	int	int_limit;
	int	rel_bits;

	stack_a_b->cur_bit = 0;
	stack_a_b->cur_int_limit = 0;
	stack_a_b->cur_bit_value = 1;
	int_limit = stack_a_b->length_a - 1;
	rel_bits = 0;
	while (int_limit >>= 1)
	{
		rel_bits++;
	}
	stack_a_b->rel_bits = rel_bits;
}
