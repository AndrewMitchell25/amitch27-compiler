#!/bin/sh
make

for testfile in test/printer/good*.bminor
do
	if ./bminor --print $testfile
	then
		echo "$testfile success (SUCCESS)"
	else
		echo "$testfile failure (FAILURE)"
	fi
done

for testfile in test/printer/bad*.bminor
do
	if ./bminor --print $testfile
	then
		echo "$testfile success (FAILURE)"
	else
		echo "$testfile failure (SUCCESS)"
	fi
done