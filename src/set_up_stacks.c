/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:30:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 11:24:48 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*malloc_int(int i);

t_stack_a_b	*set_up_stacks(t_inp_chec *checked_input)
{
	t_stack_a_b	*stack_a_b;
	t_list_dc	*new_node;
	int			i;

	stack_a_b = malloc(sizeof(*stack_a_b));
	if (!stack_a_b)
		return (raise_error_inp(checked_input));
	stack_a_b->b = NULL;
	stack_a_b->length_b = 0;
	stack_a_b->length_a = checked_input->num;
	stack_a_b->a = stack_add_first(checked_input->int_list[0]);
	if (!stack_a_b->a)
		return (raise_error_inp_stack(checked_input, &stack_a_b));
	i = 1;
	while (i < checked_input->num)
	{
		new_node = add_int_node(&stack_a_b->a, checked_input->int_list[i]);
		if (!new_node)
			return (raise_error_inp_stack(checked_input, &stack_a_b));
		i++;
	}
	initilise_sorting_params(stack_a_b);
	free_checked_input(checked_input);
	return (stack_a_b);
}

t_list_dc	*stack_add_first(int i)
{
	int			*num;
	t_list_dc	*new_node;

	num = malloc_int(i);
	if (!num)
		return (NULL);
	new_node = dc_lst_new(num);
	if (!new_node)
	{
		free(num);
		return (NULL);
	}
	return (new_node);
}

t_list_dc	*add_int_node(t_list_dc **stack, int i)
{
	int			*num;
	t_list_dc	*new_node;

	num = malloc_int(i);
	if (!num)
		return (NULL);
	new_node = dc_lst_new(num);
	if (!new_node)
	{
		free(num);
		return (NULL);
	}
	dc_lst_add_back(stack, new_node);
	return (*stack);
}
static int	*malloc_int(int i)
{
	int	*num;

	num = malloc(sizeof(*num));
	if (!num)
		return (NULL);
	*num = i;
	return (num);
}
