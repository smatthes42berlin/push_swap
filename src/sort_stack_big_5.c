/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 17:09:37 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a_b	*sort_big_5(t_stack_a_b *stack_a_b)
{
	int	i;

	i = 0;
	while (i < stack_a_b->rel_bits + 1)
	{
		stack_a_b->cur_int_limit = ft_pow(2, i + 1);
		stack_a_b->cur_bit_value = ft_pow(2, i);
		stack_a_b->cur_bit = i;
		push_small_to_b(stack_a_b);
		push_back_cond_to_a(stack_a_b);
		i++;
	}
	push_back_all_to_a(stack_a_b);
	return (stack_a_b);
}

void	push_back_all_to_a(t_stack_a_b *stack_a_b)
{
	int	i;
	int	init_length_b;

	i = 0;
	init_length_b = stack_a_b->length_b;
	while (i < init_length_b)
	{
		push_a(stack_a_b);
		i++;
	}
}

void	push_back_cond_to_a(t_stack_a_b *stack_a_b)
{
	int	i;
	int	init_length_b;
	int	cur_val_top_b;

	i = 0;
	init_length_b = stack_a_b->length_b;
	cur_val_top_b = *(int *)(stack_a_b->b->content);
	while (i < init_length_b)
	{
		if (cur_val_top_b < stack_a_b->cur_int_limit)
			rotate_b(stack_a_b);
		else
			push_a(stack_a_b);
		if (stack_a_b->b && stack_a_b->b->content)
			cur_val_top_b = *(int *)(stack_a_b->b->content);
		i++;
	}
}

void	push_small_to_b(t_stack_a_b *stack_a_b)
{
	int i;
	int init_length_a;
	int cur_val_top_a;

	i = 0;
	init_length_a = stack_a_b->length_a;
	while (i < init_length_a)
	{
		cur_val_top_a = *(int *)(stack_a_b->a->content);
		if ((cur_val_top_a & stack_a_b->cur_bit_value) == 0)
			push_b(stack_a_b);
		else
			rotate_a(stack_a_b);
		i++;
	}
}