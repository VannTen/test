#!/bin/bash

CC=gcc
fmt_array=(\
	'%5d%5d'
'%5o%5o'
'%5i%5i'
'%5u%5u'
'%5x%5x'
'%5X%5X'
'%5D%5D'
'%5U%5U'
'%5O%5O'
'%5p%5p'
'%5c%5c'
'%5s%5s'
'%5lc%5lc'
'%5ls%5ls'
'%#-d%#-d'
'%#o%#o'
'%#-i%#-i'
'%#-u%#-u'
'%#-x%#-x'
'%#-X%#-X'
'%#-D%#-D'
'%#-U%#-U'
'%#-O%#-O'
'%#-p%#-p'
'%#-c%#-c'
'%#-s%#-s'
'%#-lc%#-lc'
'%#-ls%#-ls'
'dsada%ddesdesdsada%ddesdes'
'dsada%odesdesdsada%odesdes'
'dsada%idesdesdsada%idesdes'
'dsada%udesdesdsada%udesdes'
'dsada%xdesdesdsada%xdesdes'
'dsada%Xdesdesdsada%Xdesdes'
'dsada%Ddesdesdsada%Ddesdes'
'dsada%Udesdesdsada%Udesdes'
'dsada%Odesdesdsada%Odesdes'
'dsada%pdesdesdsada%pdesdes'
'dsada%cdesdesdsada%cdesdes'
'dsada%sdesdesdsada%sdesdes'
'dsada%lcdesdesdsada%lcdesdes'
'dsada%lsdesdesdsada%lsdesdes'
'dsada%#0+-74.32ddesdesdsada%#0+-74.32ddesdes'
'dsada%#0+-74.32odesdesdsada%#0+-74.32odesdes'
'dsada%#0+-74.32idesdesdsada%#0+-74.32idesdes'
'dsada%#0+-74.32udesdesdsada%#0+-74.32udesdes'
'dsada%#0+-74.32xdesdesdsada%#0+-74.32xdesdes'
'dsada%#0+-74.32Xdesdesdsada%#0+-74.32Xdesdes'
'dsada%#0+-74.32Ddesdesdsada%#0+-74.32Ddesdes'
'dsada%#0+-74.32Udesdesdsada%#0+-74.32Udesdes'
'dsada%#0+-74.32Odesdesdsada%#0+-74.32Odesdes'
'dsada%#0+-74.32pdesdesdsada%#0+-74.32pdesdes'
'dsada%#0+-74.32cdesdesdsada%#0+-74.32cdesdes'
'dsada%#0+-74.32sdesdesdsada%#0+-74.32sdesdes'
'dsada%#0+-74.32lcdesdesdsada%#0+-74.32lcdesdes'
'dsada%#0+-74.32lsdesdesdsada%#0+-74.32lsdesdes'
'dsada%#0+-0.0ddesdesdsada%#0+-0.0ddesdes'
'dsada%#0+-0.0odesdesdsada%#0+-0.0odesdes'
'dsada%#0+-0.0idesdesdsada%#0+-0.0idesdes'
'dsada%#0+-0.0udesdesdsada%#0+-0.0udesdes'
'dsada%#0+-0.0xdesdesdsada%#0+-0.0xdesdes'
'dsada%#0+-0.0Xdesdesdsada%#0+-0.0Xdesdes'
'dsada%#0+-0.0Ddesdesdsada%#0+-0.0Ddesdes'
'dsada%#0+-0.0Udesdesdsada%#0+-0.0Udesdes'
'dsada%#0+-0.0Odesdesdsada%#0+-0.0Odesdes'
'dsada%#0+-0.0pdesdesdsada%#0+-0.0pdesdes'
'dsada%#0+-0.0cdesdesdsada%#0+-0.0cdesdes'
'dsada%#0+-0.0sdesdesdsada%#0+-0.0sdesdes'
'dsada%#0+-0.0lcdesdesdsada%#0+-0.0lcdesdes'
'dsada%#0+-0.0lsdesdesdsada%#0+-0.0lsdesdes'
'dsada%#0+20.0ddesdesdsada%#0+20.0ddesdes'
'dsada%#0+20.0odesdesdsada%#0+20.0odesdes'
'dsada%#0+20.0idesdesdsada%#0+20.0idesdes'
'dsada%#0+20.0udesdesdsada%#0+20.0udesdes'
'dsada%#0+20.0xdesdesdsada%#0+20.0xdesdes'
'dsada%#0+20.0Xdesdesdsada%#0+20.0Xdesdes'
'dsada%#0+20.0Ddesdesdsada%#0+20.0Ddesdes'
'dsada%#0+20.0Udesdesdsada%#0+20.0Udesdes'
'dsada%#0+20.0Odesdesdsada%#0+20.0Odesdes'
'dsada%#0+20.0pdesdesdsada%#0+20.0pdesdes'
'dsada%#0+20.0cdesdesdsada%#0+20.0cdesdes'
'dsada%#0+20.0sdesdesdsada%#0+20.0sdesdes'
'dsada%#0+20.0lcdesdesdsada%#0+20.0lcdesdes'
'dsada%#0+20.0lsdesdesdsada%#0+20.0lsdesdes'
)
arg_array=(\
	15,45\
	15,45\
	15,45\
	15,45\
	15,45\
	15,45\
	15,45\
	15,45\
	15,45\
	\(void*\)255,\(void*\)0\
	\'k\'\,\'k\'\
	\"string\",\"string\"\
	L\'й\',L\'й\'\
	L\"Русский\",L\"Русский\"\
	)
includelib='-iquote.. -iquote../includes'
if [ "$1" = "debug" ]
then
	debug_make=debug
	debug_flags='-fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer'
fi
error_flags='-g -Wall -Werror -Wextra -Wno-format'
test_src_file=simple_test.c
search_lib=-L..
link_lib=-lft
count=${#fmt_array[@]}-1
count_2=${#arg_array[@]}

make $debug_make -C .. -j -l 2.8 || exit 255
for ((i=0;i<=count;i++))
do
	echo -e "\nTesting format_string"  \"${fmt_array[i]}\" with args \(${arg_array[$((i%count_2))]}\)
	if ! $CC $error_flags $debug_flags\
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
if [ "$1" = "debug" ]
then
	echo Debugging
else
	echo Test leaks
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
fi
done
