/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_arr_len_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:02:08 by smatthes          #+#    #+#             */
/*   Updated: 2023/06/26 14:02:13 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include "../test_libft.h"

void	setUp(void){};
void	tearDown(void){};

void	arr_len(void)
{
	char	*src[10];
	char	**src2;

	src[0] = NULL;
	src[1] = "1";
	src[2] = "2";
	printf("src is %s\n\n", src[0]);
	TEST_ASSERT_EQUAL_size_t(0, ft_arr_len_char(src));
	src[0] = "0";
	src[1] = "1";
	src[2] = "2";
	src[3] = NULL;
	printf("src is %s\n\n", src[0]);
	TEST_ASSERT_EQUAL_size_t(3, ft_arr_len_char(src));
	src2 = NULL;
	TEST_ASSERT_EQUAL_size_t(0, ft_arr_len_char(src2));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(arr_len);
	UNITY_END();
	return (0);
}
