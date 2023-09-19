/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_stacks_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:30:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/19 15:41:37 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	ft_printf_fd(2, "Error\n");
}

void	free_checked_input(t_inp_chec *checked_input)
{
	free(checked_input->int_list);
	free(checked_input);
}

void	free_stack_a_b(t_stack_a_b **stack_a_b)
{
	dc_lst_clear(&(*stack_a_b)->a, &free);
	free(*stack_a_b);
}

t_stack_a_b	*raise_error_inp(t_inp_chec *checked_input)
{
	print_error();
	free_checked_input(checked_input);
	return (NULL);
}

t_stack_a_b	*raise_error_inp_stack(t_inp_chec *checked_input,
									t_stack_a_b **stack_a_b)
{
	print_error();
	free_checked_input(checked_input);
	free_stack_a_b(stack_a_b);
	return (NULL);
}
