# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_input.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 09:17:17 by smatthes          #+#    #+#              #
#    Updated: 2023/09/19 18:17:07 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make -C ../

check_memory_leaks() {
    not_leaking=$(echo $@ | grep "All heap blocks were freed -- no leaks are possible" | wc -l)
    if [ "$not_leaking" == "1" ]; then
        echo -n -e "P: MEM"
    else
        echo -n -e "FAILED: MEM"
    fi
}

args=""

get_random_arr() {
    count=$1
    upper_lim=$2
    lower_lim=$3

    entries=$(shuf -i $lower_lim-$upper_lim -n $count)
    result_arr=($entries)

    for i in "${!result_arr[@]}"; do
        sign=$(((RANDOM % 2) * 2 - 1))
        result_arr[$i]=$((sign * result_arr[$i]))
    done

    args="${result_arr[@]}"
}

run_random_valid_input() {
    count=$(shuf -i 1-500 -n 1)
    lower_lim=0
    upper_lim=2147483648
    # upper_lim=214748364800000000
    get_random_arr $count $upper_lim $lower_lim
    test_v "$args"
}

PASSED='=>P: Func'
FAILED='=>FAILED: Func'

test_valid() {
    res=$(../push_swap $@ 2>&1)
    res_vg=$(valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ../push_swap $@ 2>&1)
    check_memory_leaks $res_vg
    if [ "$res" != "Error" ]; then echo $PASSED; else echo $FAILED; fi
}

test_invalid() {
    res=$(../push_swap $@ 2>&1)
    res_vg=$(valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ../push_swap $@ 2>&1)
    check_memory_leaks $res_vg
    if [ "$res" = "Error" ]; then echo $PASSED; else echo $FAILED; fi
}

test_v() {
    test_valid $@
    test_valid "$@"
}

test_iv() {
    test_invalid $@
    test_invalid "$@"
}

clear

for run in {1..5}; do
    run_random_valid_input
done

printf "\n\nINVALID\n"

test_iv "1 2 3 4 a"
test_iv "z 1 2 3 4 5"
test_iv "1 2 3 4 5 6 7 1"
test_iv "1 2 5 6 2147483648"
test_iv "1 2 5 6 -2147483649"
test_iv "1 ++2 5 6"
test_iv "1 --2 5 6"
test_iv "1 --2 5 \n 6"
test_iv "1 --2 ~ 5 6"
test_iv "1 2 35 435 6 5437 654 78 65 8 7 2 35"
test_invalid "\"1 2 \" \"3 4\""

printf "\n\nVALID\n"

test_v "0001 2 3 4 5 6"
test_v "-0001 2 -3 4 5 6"
test_v "0001 2 3 -4 4 5 6"
test_v "0001 2 3 -4 4    5 6"
test_v "0001 2 3 -4 4   -0000000000000000000000000000000000000000000002147483648 5 6"
test_v "0001 2 3 -4 4   0000000000000000000000000000000000000000000002147483647 5 6"
test_valid "   1    " "    3   "
test_valid "   1    " "    -3   "

echo
