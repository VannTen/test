#!/bin/bash

CC=gcc
fmt_array=(\
	%dbalaldjk%d\
	%d\
	%ls%lc\
	)
arg_array=(\
	15,25\
	51\
	L\"Русский\",L\'文\'\
	)
includelib='-iquote.. -iquote../includes'
test_src_file=simple_test.c
search_lib=-L..
link_lib=-lft
count=${#fmt_array[@]}-1
for ((i=0;i<=count;i++))
do
	if ! $CC -g -Wall -Werror -Wextra -fsanitize=address -fsanitize=undefined\
		-D FMT=\"${fmt_array[i]}\" -D ARG_LIST=${arg_array[i]} $includelib $search_lib $link_lib\
		${test_src_file}
then
	exit 255
fi
if ! diff -U 3 <(./a.out true) <(./a.out)
then
	echo Failed format string ${fmt_array[i]} with ${arg_array[i]}
	exit 1
else
	echo Succed on format string \"${fmt_array[i]}\" with args \(${arg_array[i]}\)
fi
done
