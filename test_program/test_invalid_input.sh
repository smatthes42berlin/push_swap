# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_invalid_input.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 18:20:54 by smatthes          #+#    #+#              #
#    Updated: 2023/10/05 15:29:00 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

test_iv() {
    test_invalid $@
    test_invalid "$@"
}

test_invalid() {
    res=$(../push_swap $@ 2>&1)
    res_vg=$(valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ../push_swap $@ 2>&1)
    check_memory_leaks $res_vg
    if [ "$res" = "Error" ]; then echo $PASSED; else echo $FAILED; fi
}

printf "\n\nINVALID\n"

test_iv "1 2 3 4 a"
test_iv "1 2 3 4 -"
test_iv "1 2 3 4 +"
test_iv "1 2 3 4 +-"
test_iv "1 2 3 4 -+"
test_iv "1 2 3 4 -+1"
test_iv "z 1 2 3 4 5"
test_iv "1 2 3 4 5 6 7 1"
test_iv "1 2 5 6 2147483648"
test_iv "1 2 5 6 -2147483649"
test_iv "1 a b c"
test_iv "a b c"
test_iv "1 ++2 5 6"
test_iv "1 --2 5 6"
test_iv "1 --2 5 \n 6"
test_iv "1 --2 ~ 5 6"
test_iv "1 2 35 435 6 5437 654 78 65 8 7 2 35"
test_invalid "\"1 2 \" \"3 4\""
