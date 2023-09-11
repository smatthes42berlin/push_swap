/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:13:00 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/11 16:45:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int *checked_inp;
	checked_inp = check_input(argc, argv);
	if (!checked_inp)
		return (1);
	free(checked_inp);
	return (0);
}