# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/07/02 14:25:12 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite
# $(info $(ADDHEADERLOC))


# -I Flag adds path where header files are searched during preprocessing
SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror -I. -I$(PATHLIBFT) -I$(BASEPATHSRC) -I$(BASEPATHTEST) -I.$(PATHUNITY)
ADDHEADERLOC = $(patsubst %,-I%,$(HEADERPATH))
NAME = libftprintf.a
NAMELIBFT = libft.a
TARGET_EXTENSION=out
LINK= cc
CC = cc

PATHPROJABS = /home/smatthes/42cursus/projects42/printf/
SUBFOLDERSRC = .
BASEPATHSRC = ./src/
PATHSRC = $(patsubst %,$(BASEPATHSRC)%,$(SUBFOLDERSRC))
PATHBUILD = build/
PATHOBJ = build/obj/
PATHTESTEXE = build/exe/
PATHRES = build/results/
PATHUNITY = ./libft/unity/src/
PATHLIBFT = ./libft/
BASEPATHTEST = ./srctest/
SUBFOLDERTEST = . run_tests/ read_results/ utils/ evaluate_results/

PATHTEST = $(patsubst %,$(BASEPATHTEST)%,$(SUBFOLDERTEST))
HEADERPATH = $(PATHLIBFT)src/ $(PATHUNITY) $(BASEPATHTEST)

VPATH = $(PATHSRC) $(PATHTEST) $(PATHUNITY)

SRC = 	ft_printf.c \
		ft_vdprintf.c \
		handle_p.c \
		handle_c.c \
		handle_s.c \
		handle_d_i.c \
		handle_u.c \
		handle_x.c \
		handle_cap_x.c

SRCTEST = 	test_controller.c \
			test_read.c \
			test_run.c \
			test_all.c \
			test_comb.c \
			test_single_c.c \
			test_single_d.c \
			test_single_gen.c \
			test_single_i.c \
			test_single_p.c \
			test_single_s.c \
			test_single_u.c \
			test_single_x.c \
			test_single_X.c \
			test_errors.c \
			test_single_percent.c \
			file_handling.c 

SRCTESTUNIT = 	unit/unit_ft_vdprintf.c 
SRCTESTUNITPATH = $(patsubst %,$(BASEPATHTEST)%,$(SRCTESTUNIT))

OBJFNAME = $(SRC:.c=.o)
OBJ = $(patsubst %,$(PATHOBJ)%,$(OBJFNAME))

$(info $$var is [${OBJ}])

OBJTESTFNAME = $(SRCTEST:.c=.o)
OBJTEST = $(patsubst %,$(PATHOBJ)%,$(OBJTESTFNAME))

TESTRESULT = $(PATHRES)test_results.txt
TESTRESULTUNITY = $(PATHPROJABS)$(PATHRES)test_results_unity.txt
TESTEXENAME = test_results.$(TARGET_EXTENSION)
TESTEXE = $(PATHTESTEXE)$(TESTEXENAME)

PASS = `grep -s PASS $(PATHRES)*.txt`
PASSNUM = `grep -s -c PASS $(PATHRES)*.txt`
FAIL = `grep -s FAIL $(PATHRES)*.txt`
FAILNUM = `grep -s -c FAIL $(PATHRES)*.txt`
IGNORE = `grep -s IGNORE $(PATHRES)*.txt`
IGNORENUM = `grep -s -c IGNORE $(PATHRES)*.txt`

.PHONY: all clean fclean re bonus test testunit print testwrite

all: $(NAME)

$(NAME): libft addPrintf

addPrintf:: $(OBJ)
	ar rcs $(NAME) $(OBJ)

# create object files from source files
# any path in VPATH is searched for source files
$(PATHOBJ)%.o: %.c
	$(CC) $(CFLAGS) $(ADDHEADERLOC) -c $< -o $@

# grab results from results files
test:: testclean $(NAME) testresults
	$(call color_print_heading,$(YELLOW),IGNORES,$(IGNORENUM))
	@echo "$(IGNORE)"
	$(call color_print_heading,$(RED),FAILURES,$(FAILNUM))
	@echo "$(FAIL)"
	$(call color_print_heading,$(GREEN),PASSED,$(PASSNUM))
	@echo "$(PASS)"
	@printf "\nDONE\n"

libft::
	make -C libft
	cp $(PATHLIBFT)$(NAMELIBFT) $(NAME)

testresults: $(TESTEXE)
	@-printf "\n";\
	cd $(PATHPROJABS)$(PATHTESTEXE);\
	touch $(TESTRESULTUNITY); \
	./$(TESTEXENAME) > $(TESTRESULTUNITY) 2>&1 

$(TESTEXE):: $(OBJTEST) $(PATHOBJ)unity.o
	$(LINK) -o $@ $^ -L. $(NAME)

testunit: libft $(PATHOBJ)unity.o
	$(eval CFLAGS := $(CFLAGS) $(patsubst %,-I$(BASEPATHSRC)%,$(SUBFOLDERSRC)))
	@for unit_file in $(SRCTESTUNITPATH); do \
		$(CC) $(CFLAGS) $(ADDHEADERLOC) $$unit_file $(PATHOBJ)unity.o -L. $(NAME) -o test.out;\
		./test.out; \
		rm test.out; \
	done


clean: testclean
	make -C libft clean
	$(RM) $(OBJ)

testclean:
	$(RM) $(OBJTEST)
	$(RM) $(RESULTS)
	$(RM) $(TESTEXE)
	$(RM) $(TESTRESULT)
	$(RM) $(PATHOBJ)unity.o

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

# tells makefile not to delete the following files after running
.PRECIOUS: $(TESTEXE)
.PRECIOUS: $(PATHOBJ)%.o
.PRECIOUS: $(PATHRES)%.txt

BLACK=0
RED=1
GREEN=2
YELLOW=3
BLUE=4
MAGENTA=5
CYAN=6
WHITE=7

define color_print_heading
    @tput setaf $1
	@printf "\n"
	@printf "%-20s%-s%-s%-20s" "************" $2 "($3)" "************"
	@printf "\n\n"
    @tput sgr0
endef
