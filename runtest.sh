#!/bin/sh
make

for testfile in test/parser/good*.bminor
do
	if ./bminor --print $testfile
	then
		echo "$testfile success (SUCCESS)"
	else
		echo "$testfile failure (FAILURE)"
	fi
done

for testfile in test/parser/bad*.bminor
do
	if ./bminor --print $testfile
	then
		echo "$testfile success (FAILURE)"
	else
		echo "$testfile failure (SUCCESS)"
	fi
done