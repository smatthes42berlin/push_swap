/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:28:31 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/11 16:42:35 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_input(int argc, char *argv[])
{
	char	**only_ints;
	int		*checked_input;

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

int	*raise_error(void)
{
	print_error();
	return (NULL);
}
