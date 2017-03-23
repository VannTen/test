#!/bin/bash

CC=gcc
fmt_array=(\
	%d\
	%o\
	%i\
	%u\
	%x\
	%X\
	%D\
	%U\
	%O\
	%p\
	%c\
	%s\
	%lc\
	%ls\
	dsada%ddesdes\
	dsada%odesdes\
	dsada%idesdes\
	dsada%udesdes\
	dsada%xdesdes\
	dsada%Xdesdes\
	dsada%Ddesdes\
	dsada%Udesdes\
	dsada%Odesdes\
	dsada%pdesdes\
	dsada%cdesdes\
	dsada%sdesdes\
	dsada%lcdesdes\
	dsada%lsdesdes\
	)
arg_array=(\
	15\
	15\
	15\
	15\
	15\
	15\
	15\
	15\
	15\
	\(void*\)255\
	\'k\'\
	\"string\"\
	L\'й\'\
	L\"Русский\"\
	)
includelib='-iquote.. -iquote../includes'
test_src_file=simple_test.c
search_lib=-L..
link_lib=-lft
count=${#fmt_array[@]}-1
count_2=${#arg_array[@]}

make -C .. debug -j -l 2.8
for ((i=0;i<=count;i++))
do
	if ! $CC -g -Wall -Werror -Wextra -fsanitize=address -fsanitize=undefined\
		-D FMT=\"${fmt_array[i]}\" -D ARG_LIST=${arg_array[$((i%count_2))]} $includelib $search_lib $link_lib\
		${test_src_file}
then
	echo Bad compiling format string ${fmt_array[i]} with ${arg_array[$((i%count_2))]}
	exit 255
fi
if ! diff -U 3 <(./a.out true) <(./a.out)
then
	echo Failed format string ${fmt_array[i]} with ${arg_array[$((i%count_2))]}
	exit 1
else
	echo Succed on format string \"${fmt_array[i]}\" with args \(${arg_array[$((i%count_2))]}\)
fi
done
