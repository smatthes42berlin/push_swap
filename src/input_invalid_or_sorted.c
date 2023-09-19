/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_invalid_or_sorted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:11:30 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/19 18:14:17 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_checked(t_inp_chec *checked_input);

int	input_invalid_or_sorted(t_inp_chec *checked_input)
{
	if (!checked_input)
		return (1);
	if (checked_input->num == 1)
		return (free_checked(checked_input));
	if (input_is_sorted(checked_input))
		return (free_checked(checked_input));
	return (0);
}

static int	free_checked(t_inp_chec *checked_input)
{
	free_checked_input(checked_input);
	return (1);
}