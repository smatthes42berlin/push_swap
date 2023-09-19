/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:13:00 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/19 18:54:15 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_inp_chec	*checked_input;
	t_stack_a_b	*stack_a_b;

	checked_input = check_input(argc, argv);
	if (input_invalid_or_sorted(checked_input))
		return (0);
	stack_a_b = set_up_stacks(checked_input);
	if (!stack_a_b)
		return (1);
	dc_lst_print_whole(stack_a_b->a, "short", "int");
	free_stack_a_b(&stack_a_b);
	// first convert values to ranks
	// never use values again
	// do radix sort in binary notation using bitwise operators
	// only push numbers back to a if there are bites left, that are different from zero
	// 
	// when 3 integers, size has to be between 2 and 3 or 0
	// when 5 integers, maximum of twelve instructions
	// when 100 integers, less than 700
	// when 500 integers, less than 5500
	// when i < 3, sort stack in place
	// when i < 1, stack is already sorted
	// print_int_arr(checked_input->int_list, checked_input->num);
	return (0);
}

// implement dual linked list funcs
// set up 2 stacks
// stack 2 is empty
// all values into first stack
// double linked list
// first argument at top of the stack -> always add to back of list
// set up all necessary operations
// swap => swap first 2 elements, do nothing if there is only one or no elements
// push => take first element and put it at top of other stack
// rotate => shift all elements one up, first elem becomes last one
// reverse rotate => shift all elements down one, last elem becomes first one