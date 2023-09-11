/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_only_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:28:31 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/11 16:07:07 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_input_only_int(int argc, char *argv[])
{
	if (argc == 2)
		return (check_one_string_list(&argv[1]));
	else
		return (check_many_string_args(argc - 1, &argv[1]));
}

char	**check_one_string_list(char **arg_list)
{
	char	**inp_str;

	inp_str = ft_split(arg_list[0], ' ');
	return (trim_check_str_list(inp_str));
}

char	**check_many_string_args(int num_arg, char **arg_list)
{
	char	**inp_str;

	inp_str = ft_arr_cpy_char(arg_list, num_arg);
	return (trim_check_str_list(inp_str));
}

char	**trim_check_str_list(char **str_list)
{
	if (!str_list)
		return (NULL);
	str_list = trim_str_list(str_list);
	if (!str_list)
		return (NULL);
	return (check_each_item(str_list));
}
