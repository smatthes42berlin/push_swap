/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_dupli_range.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:28:31 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 15:29:59 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inp_chec	*check_dupli_int_range(char **only_ints)
{
	int			int_len;
	int			cur_int;
	t_inp_chec	*res;

	int_len = ft_arr_len_char(only_ints);
	res = malloc(sizeof(*res));
	if (!res)
		return (free_char(only_ints));
	res->int_list = malloc(sizeof(res->int_list) * int_len);
	if (!(res->int_list))
		return (free_struct_char(only_ints, res));
	res->num = 0;
	while (only_ints[res->num])
	{
		if (!check_int_range(only_ints[res->num], &cur_int))
			return (free_struct_list_char(only_ints, res));
		if (check_duplicates(cur_int, res->int_list, res->num) == -1)
			return (free_struct_list_char(only_ints, res));
		res->int_list[res->num] = cur_int;
		res->num++;
	}
	free_str_arr_null(only_ints);
	return (res);
}

t_inp_chec	*free_char(char **only_ints)
{
	free_str_arr_null(only_ints);
	return (NULL);
}

t_inp_chec	*free_struct_char(char **only_ints, t_inp_chec *res)
{
	free(res);
	return (free_char(only_ints));
}

t_inp_chec	*free_struct_list_char(char **only_ints, t_inp_chec *res)
{
	free(res->int_list);
	return (free_struct_char(only_ints, res));
}