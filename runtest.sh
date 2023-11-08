#!/bin/sh
make

for testfile in test/resolve/good*.bminor
do
	if ./bminor --resolve $testfile
	then
		echo "$testfile success (SUCCESS)"
	else
		echo "$testfile failure (FAILURE)"
	fi
done

for testfile in test/resolve/bad*.bminor
do
	if ./bminor --resolve $testfile
	then
		echo "$testfile success (FAILURE)"
	else
		echo "$testfile failure (SUCCESS)"
	fi
done