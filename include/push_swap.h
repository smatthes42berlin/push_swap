/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:46:44 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/19 18:14:29 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_main.h"

typedef struct s_inp_chec
{
	int			*int_list;
	int			num;
}				t_inp_chec;

typedef struct s_stack_a_b
{
	t_list_dc	*a;
	t_list_dc	*b;
	int			length_a;
	int			length_b;
}				t_stack_a_b;

/* check input */

t_inp_chec		*check_input(int argc, char *argv[]);
char			**check_input_only_int(int argc, char *argv[]);
char			**check_one_string_list(char **argv);
char			**check_many_string_args(int argc, char **argv);
char			**trim_check_str_list(char **str_list);
char			**trim_str_list(char **str_list);
char			**check_each_item(char **str_list);
int				check_item(char *str);
t_inp_chec		*check_dupli_int_range(char **only_ints);
int				check_duplicates(int cur_int, int *res_arr, int num);
int				check_int_range(char *int_str, int *res_int);
int				ft_strlen_1_to_9(char *int_str);
t_inp_chec		*free_char(char **only_ints);
t_inp_chec		*free_struct_char(char **only_ints, t_inp_chec *res);
t_inp_chec		*free_struct_list_char(char **only_ints, t_inp_chec *res);
int				input_is_sorted(t_inp_chec *checked_input);
int				input_invalid_or_sorted(t_inp_chec *checked_input);

/* set up stacks */

t_stack_a_b		*set_up_stacks(t_inp_chec *checked_input);
t_list_dc		*add_int_node(t_list_dc **stack, int i);
t_list_dc		*stack_add_first(int i);
t_stack_a_b		*raise_error_inp(t_inp_chec *checked_input);
t_stack_a_b	*raise_error_inp_stack(t_inp_chec *checked_input,
									t_stack_a_b **stack_a_b);
void			free_checked_input(t_inp_chec *checked_input);
void			free_stack_a_b(t_stack_a_b **stack_a_b);

#endif