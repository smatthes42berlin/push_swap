# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 18:10:09 by smatthes          #+#    #+#              #
#    Updated: 2023/09/12 18:10:54 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make

cc main.c -L. -lft -I./include

./a.out
