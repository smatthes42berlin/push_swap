#!/bin/bash

clear

rm -rf submission
mkdir submission
mkdir submission/libft

find ./libft/src -name \*.c -exec cp {} submission/libft \;
cp ./libft/Makefile_submit ./submission/libft/Makefile
cp ./libft/Makefile_src ./submission/libft/Makefile_src
cp ./libft/libft.h ./submission/libft/libft.h

find ./src -name \*.c -exec cp {} submission/ \;
cp ./src/ft_printf.h ./submission/ft_printf.h
cp ./Makefile_submit ./submission/Makefile

# make -C submission/libft/ all
# make -C submission/libft/ clean
# make -C submission/libft/ re
# make -C submission/libft/ fclean
# make -C submission/libft/ all
# make -C submission/libft/ all

# make -C submission/ all
# make submission/clean
# make -C submission/ re
# make submission/fclean
# make -C submission/ all
# make -C submission/ all

git clone https://github.com/Tripouille/printfTester.git ./submission/printfTester
make -C submission/printfTester m

git clone https://github.com/paulo-santana/ft_printf_tester.git ./submission/ft_printf_tester
cd submission/ft_printf_tester
sh test m
