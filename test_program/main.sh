# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 09:17:17 by smatthes          #+#    #+#              #
#    Updated: 2023/10/05 14:33:41 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make -C ../

clear

args=""

source test_utils.sh
source test_invalid_input.sh
source test_valid_input.sh
source test_sort.sh
