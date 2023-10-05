/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:13:00 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/05 11:53:06 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_inp_chec	*checked_input;
	t_stack_a_b	*stack_a_b;

	checked_input = check_input(argc, argv);
	if (input_invalid_or_sorted(checked_input))
		return (-1);
	checked_input = convert_vals_to_ranks(checked_input);
	if (!checked_input)
		return (-2);
	stack_a_b = set_up_stacks(checked_input);
	if (!stack_a_b)
		return (-3);
	stack_a_b = sort_stack_main(stack_a_b);
	free_stack_a_b(&stack_a_b);
	return (0);
}
