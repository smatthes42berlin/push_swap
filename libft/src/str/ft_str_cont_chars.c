/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cont_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:42:29 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/26 11:31:22 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_cont_chars(const char *str, const char *set)
{
	int		i;
	char	*c_occ;

	i = 0;
	while (str[i])
	{
		c_occ = ft_strchr(set, str[i]);
		if (c_occ)
			return (1);
		i++;
	}
	return (0);
}
