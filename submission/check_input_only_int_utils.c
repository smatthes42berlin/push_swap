/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_only_int_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:28:31 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/05 11:54:31 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**trim_str_list(char **str_list)
{
	char	*tmp;
	char	**str_list_start;

	str_list_start = str_list;
	while (*str_list)
	{
		tmp = *str_list;
		*str_list = ft_strtrim(tmp, " ");
		if (!*str_list)
		{
			*str_list = tmp;
			free_str_arr_null(str_list_start);
			return (NULL);
		}
		free(tmp);
		str_list++;
	}
	return (str_list_start);
}

char	**check_each_item(char **str_list)
{
	int	i;

	i = 0;
	while (str_list[i])
	{
		if (!check_item(str_list[i]))
		{
			free_str_arr_null(str_list);
			return (NULL);
		}
		i++;
	}
	return (str_list);
}

int	check_item(char *str)
{
	if (!(ft_isdigit(*str) || *str == '-' || *str == '+'))
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
