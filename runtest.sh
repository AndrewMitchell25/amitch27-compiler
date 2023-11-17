#!/bin/sh
make

for testfile in test/typecheck/good*.bminor
do
	if ./bminor --typecheck $testfile
	then
		echo "$testfile success (SUCCESS)"
	else
		echo "$testfile failure (FAILURE)"
	fi
done

for testfile in test/typecheck/bad*.bminor
do
	if ./bminor --typecheck $testfile
	then
		echo "$testfile success (FAILURE)"
	else
		echo "$testfile failure (SUCCESS)"
	fi
done