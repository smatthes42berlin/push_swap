/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:46:44 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/12 15:14:04 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_main.h"

typedef struct t_inp_chec
{
	int		*int_list;
	size_t	num;
}			t_inp_chec;

/* check input */

t_inp_chec	*check_input(int argc, char *argv[]);
char		**check_input_only_int(int argc, char *argv[]);
char		**check_one_string_list(char **argv);
char		**check_many_string_args(int argc, char **argv);
char		**trim_check_str_list(char **str_list);
char		**trim_str_list(char **str_list);
char		**check_each_item(char **str_list);
int			check_item(char *str);
t_inp_chec	*raise_error(void);
t_inp_chec	*check_dupli_int_range(char **only_ints);
int			check_duplicates(int cur_int, int *res_arr, int num);
int			check_int_range(char *int_str, int *res_int);
int			ft_strlen_1_to_9(char *int_str);
t_inp_chec	*free_char(char **only_ints);
t_inp_chec	*free_struct_char(char **only_ints, t_inp_chec *res);
t_inp_chec	*free_struct_list_char(char **only_ints, t_inp_chec *res);

#endif