/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_lst_print_one_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 09:52:03 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 18:09:37 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_main.h"

static void	print_format_cont(char *label, char *cont);
static void	print_format_ptr(char *label, t_list_dc *ptr);

void	dc_lst_print_one_str(t_list_dc *lst_ptr)
{
	if (!lst_ptr)
		return ;
	print_format_ptr("prev ptr:", lst_ptr->prev);
	print_format_cont("prev cont:", lst_ptr->prev->content);
	print_format_ptr("own ptr:", lst_ptr);
	print_format_cont("own cont:", lst_ptr->content);
	print_format_ptr("next ptr:", lst_ptr->next);
	print_format_cont("next cont:", lst_ptr->next->content);
	ft_printf(GREEN);
	ft_printf("****************************\n");
	ft_printf(WHITE);
	return ;
}

static void	print_format_cont(char *label, char *cont)
{
	ft_printf("%s\t%s\n", label, cont);
}

static void	print_format_ptr(char *label, t_list_dc *ptr)
{
	ft_printf("%s\t%p\n", label, ptr);
}
