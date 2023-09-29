/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_op_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:01:53 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 17:38:12 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_a_b *stack_a_b)
{
	dc_lst_swap(&(stack_a_b->a));
	ft_printf("sa\n");
}
void	swap_b(t_stack_a_b *stack_a_b)
{
	dc_lst_swap(&(stack_a_b->b));
	ft_printf("sb\n");
}
