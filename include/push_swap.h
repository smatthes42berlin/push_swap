/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:46:44 by smatthes          #+#    #+#             */
/*   Updated: 2023/09/11 16:03:48 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_main.h"

/* check input */

int		*check_input(int argc, char *argv[]);
char	**check_input_only_int(int argc, char *argv[]);
char	**check_one_string_list(char **argv);
char	**check_many_string_args(int argc, char **argv);
char	**trim_check_str_list(char **str_list);
char	**trim_str_list(char **str_list);
char	**check_each_item(char **str_list);
int		check_item(char *str);
void	print_error(void);
int		*raise_error(void);
int		*check_dupli_int_range(char **only_ints);
int		check_duplicates(int cur_int, int *res_arr, int num);
int		check_int_range(char *int_str, int *res_int);
int		ft_strlen_1_to_9(char *int_str);
int		*free_char_null(char **only_ints, int *res_arr);

#endif