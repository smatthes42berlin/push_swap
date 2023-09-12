/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:13:00 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 15:32:13 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_inp_chec	*checked_input;

	checked_input = check_input(argc, argv);
	if (!checked_input)
		return (1);
	print_int_arr(checked_input->int_list, checked_input->num);
	free(checked_input->int_list);
	free(checked_input);
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