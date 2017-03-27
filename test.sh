#!/bin/bash

CC=gcc
fmt_array=(\
	'%%%%%%%%%%'
'%5%%.5%'
'%0#%'
'%%%%%67desde%%%%%%%%%'
'%%%%'
'%5%'
'%+%'
'%.0%'
'%-5%'
'%%%k'
'%ll%'
'%%d'
'%h%'
'%hh%'
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
	'%0+5d%0+5d'
'%0#5o%0#5o'
'%0+5i%0+5i'
'%05u%05u'
'%0#5x%0#5x'
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
'dsada%#0+-30.15ddesdesdsada%#0+-20.30ddesdes'
'dsada%#0+-30.15odesdesdsada%#0+-20.30odesdes'
'dsada%#0+-30.15idesdesdsada%#0+-20.30idesdes'
'dsada%#0+-30.15udesdesdsada%#0+-20.30udesdes'
'dsada%#0+-30.15xdesdesdsada%#0+-20.30xdesdes'
'dsada%#0+-30.15Xdesdesdsada%#0+-20.30Xdesdes'
'dsada%#0+-30.15Ddesdesdsada%#0+-20.30Ddesdes'
'dsada%#0+-30.15Udesdesdsada%#0+-20.30Udesdes'
'dsada%#0+-30.15Odesdesdsada%#0+-20.30Odesdes'
'dsada%#0+-30.15pdesdesdsada%#0+-20.30pdesdes'
'dsada%#0+-30.15cdesdesdsada%#0+-20.30cdesdes'
'dsada%#0+-30.15sdesdesdsada%#0+-20.30sdesdes'
'dsada%#0+-30.15lcdesdesdsada%#0+-20.30lcdesdes'
'dsada%#0+-30.15lsdesdesdsada%#0+-20.30lsdesdes'
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
'Preci:%4$dField:%3$d%2$*3$.*4$dPreci:%4$dField:%4$d%1$*4$.*3$d'
'Preci:%4$dField:%3$d%2$*3$.*4$oPreci:%4$dField:%4$d%1$*4$.*3$o'
'Preci:%4$dField:%3$d%2$*3$.*4$iPreci:%4$dField:%4$d%1$*4$.*3$i'
'Preci:%4$dField:%3$d%2$*3$.*4$uPreci:%4$dField:%4$d%1$*4$.*3$u'
'Preci:%4$dField:%3$d%2$*3$.*4$xPreci:%4$dField:%4$d%1$*4$.*3$x'
'Preci:%4$dField:%3$d%2$*3$.*4$XPreci:%4$dField:%4$d%1$*4$.*3$X'
'Preci:%4$dField:%3$d%2$*3$.*4$DPreci:%4$dField:%4$d%1$*4$.*3$D'
'Preci:%4$dField:%3$d%2$*3$.*4$UPreci:%4$dField:%4$d%1$*4$.*3$U'
'Preci:%4$dField:%3$d%2$*3$.*4$OPreci:%4$dField:%4$d%1$*4$.*3$O'
'Preci:%4$dField:%3$d%2$*3$.*4$pPreci:%4$dField:%4$d%1$*4$.*3$p'
'Preci:%4$dField:%3$d%2$*3$.*4$cPreci:%4$dField:%4$d%1$*4$.*3$c'
'Preci:%4$dField:%3$d%2$*3$.*4$sPreci:%4$dField:%4$d%1$*4$.*3$s'
'Preci:%4$dField:%3$d%2$*3$.*4$lcPreci:%4$dField:%4$d%1$*4$.*3$lc'
'Preci:%4$dField:%3$d%2$*3$.*4$lsPreci:%4$dField:%4$d%1$*4$.*3$s'
'Preci:%4$dField:%$3d%2$*3$.*4$d\nPreci:%4$dField:%4$d%1$*4$.*3$d'
'Preci:%4$dField:%$3d%2$*3$.*4$o\nPreci:%4$dField:%4$d%1$*4$.*3$o'
'Preci:%4$dField:%$3d%2$*3$.*4$i\nPreci:%4$dField:%4$d%1$*4$.*3$i'
'Preci:%4$dField:%$3d%2$*3$.*4$u\nPreci:%4$dField:%4$d%1$*4$.*3$u'
'Preci:%4$dField:%$3d%2$*3$.*4$x\nPreci:%4$dField:%4$d%1$*4$.*3$x'
'Preci:%4$dField:%$3d%2$*3$.*4$X\nPreci:%4$dField:%4$d%1$*4$.*3$X'
'Preci:%4$dField:%$3d%2$*3$.*4$D\nPreci:%4$dField:%4$d%1$*4$.*3$D'
'Preci:%4$dField:%$3d%2$*3$.*4$U\nPreci:%4$dField:%4$d%1$*4$.*3$U'
'Preci:%4$dField:%$3d%2$*3$.*4$O\nPreci:%4$dField:%4$d%1$*4$.*3$O'
'Preci:%4$dField:%$3d%2$*3$.*4$p\nPreci:%4$dField:%4$d%1$*4$.*3$p'
'Preci:%4$dField:%$3d%2$*3$.*4$c\nPreci:%4$dField:%4$d%1$*4$.*3$c'
'Preci:%4$dField:%$3d%2$*3$.*4$s\nPreci:%4$dField:%4$d%1$*4$.*3$s'
'Preci:%4$dField:%$3d%2$*3$.*4$lc\nPreci:%4$dField:%4$d%1$*4$.*3$lc'
'Preci:%4$dField:%$3d%2$*3$.*4$ls\nPreci:%4$dField:%4$d%1$*4$.*3$s'
)
arg_array=(\
	-150000,45,20,10\
	15,0,20,10\
	1590090,45,-20,10\
	15,489895,20,10\
	15,0,20,10\
	15,489665,-20,10\
	158976,45,-20,10\
	158989,45,20,-10\
	15,4898765,20,10\
	\(void*\)255,\(void*\)0,20,10\
	\'k\'\,\'k\',20,10\
	\"string\",\"string\",20,10\
	L\'й\',L\'й\',20,10\
	L\"Русский\",L\"Русский\",20,10\
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
if ! diff -aU 3 <(./a.out true) <(./a.out)
then
	echo Failed format string \"${fmt_array[i]}\" with \(${arg_array[$((i%count_2))]}\)
	exit 1
else
	echo Succed on format string \"${fmt_array[i]}\" with args \(${arg_array[$((i%count_2))]}\)
fi
if [ "$1" = "debug" ]
then
	echo Debugging
elif [ "1$" = "leaks" ]
then
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
