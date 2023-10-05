/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list_to_ranks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:50:27 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 11:16:09 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inp_chec	*convert_vals_to_ranks(t_inp_chec *checked_input)
{
	int			i;
	t_inp_chec	*checked_input_ranks;

	i = 0;
	checked_input_ranks = malloc(sizeof(*checked_input_ranks));
	if (!checked_input_ranks)
		return (raise_error_struct(checked_input));
	checked_input_ranks->int_list = malloc(sizeof(int) * (checked_input)->num);
	if (!(checked_input_ranks->int_list))
		return (raise_error_array(checked_input, checked_input_ranks));
	while (i < (checked_input)->num)
	{
		checked_input_ranks->int_list[i] = get_rank(i, checked_input);
		i++;
	}
	checked_input_ranks->num = checked_input->num;
	free_checked_input(checked_input);
	return (checked_input_ranks);
}

int	get_rank(int to_rank_index, t_inp_chec *checked_input)
{
	int	comp_index;
	int	rank;
	int	to_rank_val;
	int	comp_val;

	rank = 0;
	comp_index = 0;
	to_rank_val = checked_input->int_list[to_rank_index];
	while (comp_index < (checked_input)->num)
	{
		comp_val = checked_input->int_list[comp_index];
		if (to_rank_val > comp_val)
			rank++;
		comp_index++;
	}
	return (rank);
}
