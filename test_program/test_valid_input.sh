# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_valid_input.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 18:25:06 by smatthes          #+#    #+#              #
#    Updated: 2023/09/30 18:28:18 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

test_valid() {
    res=$(../push_swap $@ 2>&1)
    res_vg=$(valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ../push_swap $@ 2>&1)
    check_memory_leaks $res_vg
    if [ "$res" != "Error" ]; then echo $PASSED; else echo $FAILED; fi
}

test_v() {
    test_valid $@
    test_valid "$@"
}

run_random_valid_input() {
    count=$(shuf -i 1-500 -n 1)
    lower_lim=0
    upper_lim=2147483648
    get_random_arr $count $upper_lim $lower_lim
    test_v "$args"
}

printf "\n\nRANDOM\n"
for run in {1..5}; do
    run_random_valid_input
done

printf "\n\nVALID\n"

test_v "0001 2 3 4 5 6"
test_v "-0001 2 -3 4 5 6"
test_v "0001 2 3 -4 4 5 6"
test_v "0001 2 3 -4 4    5 6"
test_v "0001 2 3 -4 4   -0000000000000000000000000000000000000000000002147483648 5 6"
test_v "0001 2 3 -4 4   0000000000000000000000000000000000000000000002147483647 5 6"
test_valid "   1    " "    3   "
test_valid "   1    " "    -3   "
