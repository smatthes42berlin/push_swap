/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_dupli_range_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:28:31 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/05 11:59:24 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int cur_int, int *res_arr, int num)
{
	int	i;

	i = int_arr_int_index(res_arr, cur_int, num);
	if (i >= 0)
		return (-1);
	return (1);
}

// INT_MAX and INT_MIN have 10 digits
int	check_int_range(char *int_str, int *res_int)
{
	int		digit_length;
	long	res_int_unchecked;

	digit_length = ft_strlen_1_to_9(int_str);
	if (digit_length > 11)
		return (0);
	res_int_unchecked = ft_atoi_base_l(int_str, "0123456789");
	if (res_int_unchecked > INT_MAX || res_int_unchecked < INT_MIN)
		return (0);
	*res_int = res_int_unchecked;
	return (1);
}

int	ft_strlen_1_to_9(char *int_str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (int_str[i])
	{
		if (ft_isdigit(int_str[i]) && int_str[i] != '0')
			break ;
		i++;
	}
	len = ft_strlen(&int_str[i]);
	return (len);
}
