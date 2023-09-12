/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:28:31 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 10:12:56 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct t_inp_chec	*check_input(int argc, char *argv[])
{
	char		**only_ints;
	t_inp_chec	*checked_input;

	if (argc <= 1)
		return (NULL);
	only_ints = check_input_only_int(argc, argv);
	if (!only_ints)
		return (raise_error());
	checked_input = check_dupli_int_range(only_ints);
	if (!checked_input)
		return (raise_error());
	return (checked_input);
}

t_inp_chec	*raise_error(void)
{
	ft_printf_fd(2, "Error\n");
	return (NULL);
}
