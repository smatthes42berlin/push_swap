# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_utils.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 18:19:03 by smatthes          #+#    #+#              #
#    Updated: 2023/10/05 11:24:06 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PASSED='PASS'
FAILED='FAIL'

check_memory_leaks() {
    not_leaking=$(echo $@ | grep "All heap blocks were freed -- no leaks are possible" | wc -l)
    if [ "$not_leaking" == "1" ]; then
        echo -n -e "PASS "
    else
        echo -n -e "FAIL "
    fi
}

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
