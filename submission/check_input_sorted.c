/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:02:50 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/05 11:53:36 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_is_sorted(t_inp_chec *checked_input)
{
	int	i;
	int	current;
	int	next;

	i = 0;
	while (i < checked_input->num - 1)
	{
		current = checked_input->int_list[i];
		next = checked_input->int_list[i + 1];
		if (next < current)
			return (0);
		i++;
	}
	return (1);
}
