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
	%\#-d\
	%\#-o\
	%\#-i\
	%\#-u\
	%\#-x\
	%\#-X\
	%\#-D\
	%\#-U\
	%\#-O\
	%\#-p\
	%\#-c\
	%\#-s\
	%\#-lc\
	%\#-ls\
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
	dsada%-74.32ddesdes\
	dsada%-74.32odesdes\
	dsada%-74.32idesdes\
	dsada%-74.32udesdes\
	dsada%-74.32xdesdes\
	dsada%-74.32Xdesdes\
	dsada%-74.32Ddesdes\
	dsada%-74.32Udesdes\
	dsada%-74.32Odesdes\
	dsada%-74.32pdesdes\
	dsada%-74.32cdesdes\
	dsada%-74.32sdesdes\
	dsada%-74.32lcdesdes\
	dsada%-74.32lsdesdes\
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
debug_flags='-fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer'
error_flags='-g -Wall -Werror -Wextra -Wno-format'
test_src_file=simple_test.c
search_lib=-L..
link_lib=-lft
count=${#fmt_array[@]}-1
count_2=${#arg_array[@]}

make -C .. -j -l 2.8 || exit 255
for ((i=0;i<=count;i++))
do
	echo -e "\nTesting format_string"  \"${fmt_array[i]}\" with args \(${arg_array[$((i%count_2))]}\)
	if ! $CC $error_flags\
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
./a.out leaks > /dev/null &
sleep 1
pid=$!
leaks $pid > /dev/null
leaks=$?
kill $pid
if [ $leaks = 0 ]
then
	echo No leaks
elif [ $leaks = 1 ]
then
	echo format string \"${fmt_array[i]}\" with args \(${arg_array[$((i%count_2))]}\) causes leaks !
	exit 1
else
	echo Error with leaks command
	exit 255
fi
done
