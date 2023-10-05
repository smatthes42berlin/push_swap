# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_sort.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 18:29:07 by smatthes          #+#    #+#              #
#    Updated: 2023/10/05 11:43:47 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

test_v_sort() {
    test_valid_sort $@
    test_valid_sort "$@"
}

test_valid_sort() {
    res_sort_ok=$(../push_swap $@ | ./checker_linux $@)
    res_vg=$(valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ../push_swap $@ 2>&1)
    res_wc=$(../push_swap $@ | wc -l)
    # check_memory_leaks $res_vg
    echo $res_sort_ok
    # echo $res_vg
    # echo $res_wc
    echo done
}

run_random_valid_input_sort() {
    count=4
    count=$(shuf -i 1-600 -n 1)
    # echo $count
    # count=0
    lower_lim=0
    upper_lim=2147483648
    get_random_arr $count $upper_lim $lower_lim
    # echo $args
    # ../push_swap "$args"
    res=$(../push_swap "$args" | ./checker_linux "$args")
    # echo $res
    res_wc=$(../push_swap "$args" | wc -l)
    # echo $res_wc
    res_vg=$(valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ../push_swap "$args" 2>&1)
    check_memory_leaks $res_vg
    # echo -e "$res"
    if [ "$res" == "OK" ]; then
        echo -n -e "PASS \n"
    else
        echo -n -e "FAIL \n"
        exit
    fi
}

run_defined_input() {

    res=$(../push_swap "$1" | ./checker_linux "$1")
    res_wc=$(../push_swap "$1" | wc -l)
    res_vg=$(valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ../push_swap "$1" 2>&1)
    check_memory_leaks $res_vg
    if [ "$res" == "OK" ]; then
        echo -n -e "PASS \n"
    else
        echo -n -e "FAIL \n"
        exit
    fi
}

for run in {1..20}; do
    run_random_valid_input_sort
done

echo
echo DEFINED
echo

run_defined_input "0 1"
run_defined_input "1 0"
run_defined_input "0 1 2"
run_defined_input "0 2 1"
run_defined_input "1 2 0"
run_defined_input "1 0 2"
run_defined_input "2 0 1"
run_defined_input "2 1 0"
run_defined_input "0 1 2 3"
run_defined_input "1 0 2 3"
run_defined_input "0 1 3 2"
run_defined_input "1 0 3 2"
run_defined_input "3 1 2 0"
run_defined_input "0 2 1 3"
run_defined_input "2 3 0 1"
run_defined_input "0 3 2 1"
run_defined_input "3 2 1 0"
run_defined_input "3 2 1 0"
run_defined_input "3 2 0 1"
run_defined_input "0 1 2 3 4"
run_defined_input "1 2 0 3 4"
run_defined_input "0 3 2 1 4"
run_defined_input "0 1 2 4 3"
run_defined_input "1 2 0 4 3"
run_defined_input "4 3 2 1 0"
run_defined_input "4 2 1 3 0"
run_defined_input "4 0 1 2 3"
run_defined_input "3 2 1 0 4"
run_defined_input "3 4 2 1 0"