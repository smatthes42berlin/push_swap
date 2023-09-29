/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list_to_ranks_free.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:50:27 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/29 10:14:18 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	ft_printf_fd(2, "Error\n");
}

t_inp_chec	*raise_error_struct(t_inp_chec *checked_input)
{
	print_error();
	free_checked_input(checked_input);
	return (NULL);
}

t_inp_chec	*raise_error_array(t_inp_chec *checked_input,
								t_inp_chec *checked_input_ranks)
{
	free(checked_input_ranks);
	return (raise_error_struct(checked_input));
}
